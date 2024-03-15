/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_parse_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:11:47 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/15 20:42:02 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	set_map_width(t_map *map, char *line)
{
	int	i;

	i = -1;
	while (line[++i] != '\n' && line[i] != '\0')
	{
		if (is_map_element(line[i]) == 0)
			print_error_and_exit("invalid map element\n");
	}
	if (i > map->width)
		map->width = i;
}

void	set_map_width_height(t_map *map, int fd)
{
	char	*line;

	line = move_to_map_element(fd);
	while (1)
	{
		if (line == NULL)
			break ;
		else if (ft_strncmp(line, "\n", 1) == 1)
			print_error_and_exit("empty line between map element\n");
		else if (is_map_element(line[0]) == 0)
			print_error_and_exit("invalid map element\n");
		else
		{
			map->height++;
			set_map_width(map, line);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	pre_set_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->map = (char **)ft_calloc(sizeof(char *), map->height + 1);
	while (++i < map->height)
		map->map[i] = (char *)ft_calloc(sizeof(char), map->width + 1);
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->map[i][j] = ' ';
		}
	}
}

void	set_map_component(t_map *map, char *line, int height_cnt, int *pos_flag)
{
	int	width;

	width = 0;
	while (line[width] != '\0' && line[width] != '\n')
	{
		if (line[width] != ' ' && line[width] != '0'
			&& line[width] != '1' && line[width] != 'D')
		{
			if (*pos_flag == 1)
				print_error_and_exit("player position must be one\n");
			*pos_flag = 1;
			map->pp.x = height_cnt;
			map->pp.y = width;
			map->dir = line[width];
		}
		map->map[height_cnt][width] = line[width];
		width++;
	}
	return ;
}

void	set_map_elements(t_map *map, char *map_path)
{
	int		fd;
	int		pos_flag;
	int		height_cnt;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("file open error\n");
	line = move_to_map_element(fd);
	pre_set_map(map);
	height_cnt = 0;
	while (1)
	{
		if (line == NULL)
			break ;
		set_map_component(map, line, height_cnt, &pos_flag);
		free(line);
		line = get_next_line(fd);
		height_cnt++;
	}
	close(fd);
}
