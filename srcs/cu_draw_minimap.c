/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:57:15 by jongmlee          #+#    #+#             */
/*   Updated: 2024/01/12 20:59:28 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_minimap(t_info *info)
{
	int	x;
	int	y;
	int	map_x;
	int	map_y;

	set_minimap(info);
	x = -1;
	while (++x < (int)(MINIMAP_SCALE * HEIGHT))
	{
		y = -1;
		while (++y < (int)(MINIMAP_SCALE * WIDTH))
		{
			map_x = get_map_idx(x, (int)(MINIMAP_SCALE * HEIGHT));
			map_y = get_map_idx(y, (int)(MINIMAP_SCALE * WIDTH));
			if (info->minimap[map_x][map_y] == '1')
				info->buf[x][y] = 16753920;
			else if (info->minimap[map_x][map_y] == 'H')
				info->buf[x][y] = 0xFF0000;
			else if (info->minimap[map_x][map_y] == 'D')
				info->buf[x][y] = 0xADD8E6;
			else
				info->buf[x][y] = 0x000000;
		}
	}
}

void	set_minimap(t_info *info)
{
	int	i;
	int	j;
	int	pos_x;
	int	pos_y;

	i = 0;
	while (i < MINIMAP_UNIT)
	{
		j = 0;
		while (j < MINIMAP_UNIT)
		{
			pos_x = (int)info->pos.x - (MINIMAP_UNIT / 2) + i;
			pos_y = (int)info->pos.y - (MINIMAP_UNIT / 2) + j;
			if (pos_x < 0 || pos_y < 0
				|| pos_x >= info->map->height || pos_y >= info->map->width)
				info->minimap[i][j] = '0';
			else
				info->minimap[i][j] = info->map->map[pos_x][pos_y];
			j++;
		}
		i++;
	}
	info->minimap[(MINIMAP_UNIT / 2)][(MINIMAP_UNIT / 2)] = 'H';
}

int	get_map_idx(int n, int len)
{
	int	i;

	i = 0;
	while (i < MINIMAP_UNIT)
	{
		if (n >= (len / MINIMAP_UNIT) * i && n < (len / MINIMAP_UNIT) * (i + 1))
			return (i);
		i++;
	}
	return (MINIMAP_UNIT - 1);
}
