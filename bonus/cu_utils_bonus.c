/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:01:27 by jongmlee          #+#    #+#             */
/*   Updated: 2024/01/15 20:42:02 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	print_error_and_exit(char *message)
{
	write(2, "\033[0;35mError\n", ft_strlen("\033[0;35mError\n"));
	write(2, message, ft_strlen(message));
	write(2, "\033[0;0m", ft_strlen("\033[0;0m"));
	exit(1);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	get_str_2d_len(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != NULL)
		i++;
	return (i);
}

void	ending_free(t_info *info)
{
	t_door	*cur;

	free(info->map->texture.no_path);
	free(info->map->texture.so_path);
	free(info->map->texture.we_path);
	free(info->map->texture.ea_path);
	free_2d_array(info->map->map);
	while (info->head != NULL)
	{
		cur = info->head;
		info->head = info->head->next;
		free(cur);
	}
}
