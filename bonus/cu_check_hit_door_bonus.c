/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_check_hit_door_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:57:37 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/15 20:42:02 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	calc_door_dist(t_info *info, t_wall *door)
{
	double	camera_x;

	camera_x = 2 * door->b / (double) WIDTH - 1;
	door->ray_dir.x = info->dir.x + info->plane.x * camera_x;
	door->ray_dir.y = info->dir.y + info->plane.y * camera_x;
	door->map.x = (int)info->pos.x;
	door->map.y = (int)info->pos.y;
	door->side = hit_door(info, door);
	if (door->side == 0)
		door->perp_wall_dist = (door->map.x - info->pos.x
				+ (1 - door->step.x) / 2) / door->ray_dir.x;
	else
		door->perp_wall_dist = (door->map.y - info->pos.y
				+ (1 - door->step.y) / 2) / door->ray_dir.y;
}

int	hit_door(t_info *info, t_wall *door)
{
	t_dpos	delta_dist;
	t_dpos	side_dist;

	delta_dist.x = fabs(1 / door->ray_dir.x);
	delta_dist.y = fabs(1 / door->ray_dir.y);
	door->step.x = 2 * (door->ray_dir.x >= 0) - 1;
	door->step.y = 2 * (door->ray_dir.y >= 0) - 1;
	if (door->ray_dir.x < 0)
		side_dist.x = (info->pos.x - door->map.x) * delta_dist.x;
	else
		side_dist.x = (door->map.x + 1.0 - info->pos.x) * delta_dist.x;
	if (door->ray_dir.y < 0)
		side_dist.y = (info->pos.y - door->map.y) * delta_dist.y;
	else
		side_dist.y = (door->map.y + 1.0 - info->pos.y) * delta_dist.y;
	return (check_hit_door(&side_dist, &delta_dist, door, info));
}

int	check_hit_door(t_dpos *side_dist, t_dpos *delta_dist,
				t_wall *door, t_info *info)
{
	int	side;

	while (42)
	{
		if (side_dist->x < side_dist->y)
		{
			side_dist->x += delta_dist->x;
			door->map.x += door->step.x;
			side = 0;
		}
		else
		{
			side_dist->y += delta_dist->y;
			door->map.y += door->step.y;
			side = 1;
		}
		if (info->map->map[door->map.x][door->map.y] == '1'
			|| info->map->map[door->map.x][door->map.y] == 'D')
			return (side);
	}
}

void	find_door_part(t_info *info, t_wall *door)
{
	door->line_height = (int)(HEIGHT / door->perp_wall_dist);
	door->draw_start = -door->line_height / 2 + HEIGHT / 2;
	if (door->draw_start < 0)
		door->draw_start = 0;
	door->draw_end = door->line_height / 2 + HEIGHT / 2;
	if (door->draw_end >= HEIGHT)
		door->draw_end = HEIGHT - 1;
	if (door->side == 0)
		door->ratio = info->pos.y + door->perp_wall_dist * door->ray_dir.y;
	else
		door->ratio = info->pos.x + door->perp_wall_dist * door->ray_dir.x;
	door->ratio -= floor(door->ratio);
}

void	put_buf_door_line(t_info *info, t_wall *door, t_door *cur)
{
	double			delta_step;
	double			tex_pos;

	door->tex.x = (int)(door->ratio * (double) TEX_WIDTH);
	if (door->side == 0 && door->ray_dir.x > 0)
		door->tex.x = TEX_WIDTH - door->tex.x - 1;
	if (door->side == 1 && door->ray_dir.y < 0)
		door->tex.x = TEX_WIDTH - door->tex.x - 1;
	delta_step = 1.0 * TEX_HEIGHT / door->line_height;
	tex_pos = (door->draw_start - HEIGHT / 2
			+ door->line_height / 2) * delta_step;
	door->a = door->draw_start - 1;
	while (++door->a < door->draw_end)
	{
		door->tex.y = (int) tex_pos & (TEX_HEIGHT - 1);
		if (cur != NULL && door->a - cur->open > 0)
			info->buf[door->a - cur->open][door->b] = info->texture[4]
			[TEX_HEIGHT * door->tex.y + door->tex.x];
		tex_pos += delta_step;
	}
}
