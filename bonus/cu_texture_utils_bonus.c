/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_texture_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:01:17 by jongmlee          #+#    #+#             */
/*   Updated: 2024/01/15 20:42:02 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	is_texture_identifier(char *line)
{
	int	result;

	result = 0;
	if (ft_strncmp(line, "NO", 3) == 0)
		result = 1;
	else if (ft_strncmp(line, "SO", 3) == 0)
		result = 2;
	else if (ft_strncmp(line, "EA", 3) == 0)
		result = 3;
	else if (ft_strncmp(line, "WE", 3) == 0)
		result = 4;
	else if (ft_strncmp(line, "F", 2) == 0)
		result = 5;
	else if (ft_strncmp(line, "C", 2) == 0)
		result = 6;
	return (result);
}

int	is_texture_element(char *line)
{
	char	**splited_line;
	int		result;

	splited_line = ft_split(line, ' ');
	result = 0;
	if (is_texture_identifier(splited_line[0]) == 0)
		result = 1;
	else if (splited_line[1] == NULL)
		result = 1;
	else if (splited_line[2] != NULL)
		result = 1;
	free_2d_array(splited_line);
	return (result);
}

void	check_color_is_valid(t_map *map, char *line, char identifier)
{
	char	**splited_line;
	int		i;
	int		j;

	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	splited_line = ft_split(line, ',');
	if (get_str_2d_len(splited_line) != 3)
		print_error_and_exit("invalid color\n");
	i = -1;
	while (++i < 3)
	{
		if (ft_strlen(splited_line[i]) > 3)
			print_error_and_exit("color value is over 255\n");
		j = -1;
		while (++j < (int)ft_strlen(splited_line[i]))
			if (ft_isdigit(splited_line[i][j]) == 0)
				print_error_and_exit("color value isn't numeric\n");
		if (identifier == 'F')
			map->texture.f_color[i] = ft_atoi(splited_line[i]);
		else if (identifier == 'C')
			map->texture.c_color[i] = ft_atoi(splited_line[i]);
	}
	free_2d_array(splited_line);
}

void	trim_textures(t_texture *texture)
{
	if (texture->no_path[ft_strlen(texture->no_path) - 1] == '\n')
		texture->no_path[ft_strlen(texture->no_path) - 1] = '\0';
	if (texture->so_path[ft_strlen(texture->so_path) - 1] == '\n')
		texture->so_path[ft_strlen(texture->so_path) - 1] = '\0';
	if (texture->we_path[ft_strlen(texture->we_path) - 1] == '\n')
		texture->we_path[ft_strlen(texture->we_path) - 1] = '\0';
	if (texture->ea_path[ft_strlen(texture->ea_path) - 1] == '\n')
		texture->ea_path[ft_strlen(texture->ea_path) - 1] = '\0';
}
