/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_cast_floor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:04:54 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/15 20:42:02 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	cast_floor(t_info *info)
{
	int	i;
	int	j;
	int	ceiling;
	int	floor;

	i = 0;
	ceiling = info->ceiling_color;
	floor = info->floor_color;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			info->buf[i][j] = ceiling;
			info->buf[HEIGHT - i - 1][j] = floor;
			j++;
		}
		i++;
	}
}
