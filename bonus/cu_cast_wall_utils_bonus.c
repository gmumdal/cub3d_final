/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_cast_wall_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:56:11 by jongmlee          #+#    #+#             */
/*   Updated: 2024/01/15 20:42:02 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	find_draw_part(t_info *info, t_wall *wall)
{
	wall->line_height = (int)(HEIGHT / wall->perp_wall_dist);
	wall->draw_start = -wall->line_height / 2 + HEIGHT / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + HEIGHT / 2;
	if (wall->draw_end >= HEIGHT)
		wall->draw_end = HEIGHT - 1;
	if (wall->side == 0)
		wall->ratio = info->pos.y + wall->perp_wall_dist * wall->ray_dir.y;
	else
		wall->ratio = info->pos.x + wall->perp_wall_dist * wall->ray_dir.x;
	wall->ratio -= floor(wall->ratio);
}

int	get_wall_color(t_info *info, t_wall *wall)
{
	int	color;

	color = 0;
	if (wall->side == 0)
	{
		if (wall->ray_dir.x >= 0)
			color = info->texture[0][TEX_HEIGHT * wall->tex.y + wall->tex.x];
		else
			color = info->texture[1][TEX_HEIGHT * wall->tex.y + wall->tex.x];
	}
	else if (wall->side == 1)
	{
		if (wall->ray_dir.y >= 0)
			color = info->texture[3][TEX_HEIGHT * wall->tex.y + wall->tex.x];
		else
			color = info->texture[2][TEX_HEIGHT * wall->tex.y + wall->tex.x];
	}
	return (color);
}

void	put_buf_wall_line(t_info *info, t_wall *wall)
{
	double	delta_step;
	double	tex_pos;

	wall->tex.x = (int)(wall->ratio * (double) TEX_WIDTH);
	if (wall->side == 0 && wall->ray_dir.x > 0)
		wall->tex.x = TEX_WIDTH - wall->tex.x - 1;
	if (wall->side == 1 && wall->ray_dir.y < 0)
		wall->tex.x = TEX_WIDTH - wall->tex.x - 1;
	delta_step = 1.0 * TEX_HEIGHT / wall->line_height;
	tex_pos = (wall->draw_start - HEIGHT / 2
			+ wall->line_height / 2) * delta_step;
	wall->a = wall->draw_start - 1;
	while (++wall->a < wall->draw_end)
	{
		wall->tex.y = (int) tex_pos & (TEX_HEIGHT - 1);
		info->buf[wall->a][wall->b] = get_wall_color(info, wall);
		tex_pos += delta_step;
	}
}
