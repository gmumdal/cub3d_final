/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_parse_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:01:07 by jongmlee          #+#    #+#             */
/*   Updated: 2024/01/15 20:42:02 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	check_map_name(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 4)
		print_error_and_exit("check map name error\n");
	if (map_name[len - 1] != 'b' || map_name[len - 2] != 'u'
		|| map_name[len - 3] != 'c' || map_name[len - 4] != '.')
		print_error_and_exit("check map name error\n");
}

int	is_map_element(char c)
{
	int	result;

	result = 0;
	if (c == ' ' || c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == 'D')
		result = 1;
	return (result);
}

void	is_duplicated_path(int identifier, char *path, t_map *map)
{
	int	i;

	i = 1;
	if (i++ != identifier)
		if (map->texture.no_path != NULL
			&& !ft_strncmp(path, map->texture.no_path, ft_strlen(path)))
			print_error_and_exit("duplicated no_path error\n");
	if (i++ != identifier)
		if (map->texture.so_path != NULL
			&& !ft_strncmp(path, map->texture.so_path, ft_strlen(path)))
			print_error_and_exit("duplicated so_path error\n");
	if (i++ != identifier)
		if (map->texture.we_path != NULL
			&& !ft_strncmp(path, map->texture.we_path, ft_strlen(path)))
			print_error_and_exit("duplicated we_path error\n");
	if (i != identifier)
		if (map->texture.ea_path != NULL
			&& !ft_strncmp(path, map->texture.ea_path, ft_strlen(path)))
			print_error_and_exit("duplicated ea_path error\n");
}

void	is_valid_path(int identifier, char *path, t_map *map)
{
	int		fd;

	if (identifier == NO || identifier == SO
		|| identifier == WE || identifier == EA)
	{
		is_duplicated_path(identifier, path, map);
		if (path[ft_strlen(path) - 1] == '\n')
			path[ft_strlen(path) - 1] = '\0';
		fd = open(path, O_RDONLY);
		if (fd < 0)
			print_error_and_exit("file open error\n");
		close(fd);
	}
}
