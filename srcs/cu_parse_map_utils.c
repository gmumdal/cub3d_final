/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_parse_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:59:45 by jongmlee          #+#    #+#             */
/*   Updated: 2024/01/12 21:00:59 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_map_element_arr(char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (line[0] == '\n')
		return (0);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (is_map_element(line[i]) == 0)
			return (0);
		if (line[i] != ' ')
			flag = 1;
		i++;
	}
	if (flag == 0)
		return (0);
	return (1);
}

char	*move_to_map_element(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			return (line);
		if (is_map_element_arr(line) == 1)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	check_map_is_surrouned(t_map *map, int h, int w)
{
	if (w - 1 >= 0 && (map->map[h][w - 1] != ' '
		&& map->map[h][w - 1] != '1'))
		print_error_and_exit("map must be closed by wall\n");
	if (w + 1 < map->width && map->map[h][w + 1] != ' '
		&& map->map[h][w + 1] != '1')
		print_error_and_exit("map must be closed by wall\n");
	if (h + 1 < map->height && map->map[h + 1][w] != ' '
		&& map->map[h + 1][w] != '1')
		print_error_and_exit("map must be closed by wall\n");
	if (h - 1 >= 0 && map->map[h - 1][w] != ' '
		&& map->map[h - 1][w] != '1')
		print_error_and_exit("map must be closed by wall\n");
}

void	check_door_is_surrounded(t_map *map, int x, int y)
{
	if ((map->map[x - 1][y] == '1' && map->map[x + 1][y] == '1') ||
		(map->map[x][y - 1] == '1' && map->map[x][y + 1] == '1'))
		return ;
	print_error_and_exit("door must be surrounded by wall\n");
}

void	check_map_is_valid(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->height)
	{
		y = -1;
		while (++y < map->width)
		{
			if ((x == 0 || x == map->height - 1)
				&& (map->map[x][y] != ' ' && map->map[x][y] != '1'))
				print_error_and_exit("map must be closed by wall\n");
			if ((y == 0 || y == map->width - 1)
				&& (map->map[x][y] != ' ' && map->map[x][y] != '1'))
				print_error_and_exit("map must be closed by wall\n");
			if (map->map[x][y] == ' ')
				check_map_is_surrouned(map, x, y);
			if (map->map[x][y] == 'D')
				check_door_is_surrounded(map, x, y);
		}
	}
	if (map->dir == 0)
		print_error_and_exit("no character\n");
}
