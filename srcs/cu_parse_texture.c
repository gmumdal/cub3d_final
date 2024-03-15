/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_parse_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:11:37 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/12 21:05:20 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_texture_path(t_map *map, char *line)
{
	char		**splited_line;
	int			identifier;

	splited_line = ft_split(line, ' ');
	identifier = is_texture_identifier(splited_line[0]);
	if (identifier == NO && map->texture.no_path == NULL)
		map->texture.no_path = ft_strdup(splited_line[1]);
	else if (identifier == SO && map->texture.so_path == NULL)
		map->texture.so_path = ft_strdup(splited_line[1]);
	else if (identifier == WE && map->texture.we_path == NULL)
		map->texture.we_path = ft_strdup(splited_line[1]);
	else if (identifier == EA && map->texture.ea_path == NULL)
		map->texture.ea_path = ft_strdup(splited_line[1]);
	else if (identifier == F && map->texture.f_color[0] == -1)
		check_color_is_valid(map, splited_line[1], 'F');
	else if (identifier == C && map->texture.c_color[0] == -1)
		check_color_is_valid(map, splited_line[1], 'C');
	else
		print_error_and_exit("identifier is duplicated\n");
	is_valid_path(identifier, splited_line[1], map);
	free_2d_array(splited_line);
	map->texture.cnt++;
}

void	get_texture(t_map *map, int fd)
{
	char	*line;

	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_map_element_arr(line) == 1)
			break ;
		else if (ft_strncmp(line, "\n", 2) == 0)
		{
			free(line);
			continue ;
		}
		else if (is_texture_element(line) == 0)
			set_texture_path(map, line);
		else
			print_error_and_exit("invalid element\n");
		free(line);
	}
	free(line);
	if (map->texture.cnt != 6)
		print_error_and_exit("number of texture is wrong\n");
	trim_textures(&map->texture);
}

void	load_file(char *map_path, t_map *map)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("file open error\n");
	init_map(map);
	get_texture(map, fd);
	get_map(map, map_path);
	close(fd);
}
