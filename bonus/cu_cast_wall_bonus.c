/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_cast_wall_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:16:37 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/15 20:42:02 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	cast_wall(t_info *info)
{
	t_wall	wall;

	wall.a = -1;
	wall.b = -1;
	while (++wall.b < WIDTH)
	{
		calc_wall_dist(info, &wall);
		find_draw_part(info, &wall);
		put_buf_wall_line(info, &wall);
	}
}

void	calc_wall_dist(t_info *info, t_wall *wall)
{
	double	camera_x;

	camera_x = 2 * wall->b / (double) WIDTH - 1;
	wall->ray_dir.x = info->dir.x + info->plane.x * camera_x;
	wall->ray_dir.y = info->dir.y + info->plane.y * camera_x;
	wall->map.x = (int)info->pos.x;
	wall->map.y = (int)info->pos.y;
	wall->side = hit_wall(info, wall);
	if (wall->side == 0)
		wall->perp_wall_dist = (wall->map.x - info->pos.x
				+ (1 - wall->step.x) / 2) / wall->ray_dir.x;
	else
		wall->perp_wall_dist = (wall->map.y - info->pos.y
				+ (1 - wall->step.y) / 2) / wall->ray_dir.y;
}

int	hit_wall(t_info *info, t_wall *wall)
{
	t_dpos	delta_dist;
	t_dpos	side_dist;

	delta_dist.x = fabs(1 / wall->ray_dir.x);
	delta_dist.y = fabs(1 / wall->ray_dir.y);
	wall->step.x = 2 * (wall->ray_dir.x >= 0) - 1;
	wall->step.y = 2 * (wall->ray_dir.y >= 0) - 1;
	if (wall->ray_dir.x < 0)
		side_dist.x = (info->pos.x - wall->map.x) * delta_dist.x;
	else
		side_dist.x = (wall->map.x + 1.0 - info->pos.x) * delta_dist.x;
	if (wall->ray_dir.y < 0)
		side_dist.y = (info->pos.y - wall->map.y) * delta_dist.y;
	else
		side_dist.y = (wall->map.y + 1.0 - info->pos.y) * delta_dist.y;
	return (check_hit_wall(&side_dist, &delta_dist, wall, info));
}

int	check_hit_wall(t_dpos *side_dist, t_dpos *delta_dist,
	t_wall *wall, t_info *info)
{
	int	side;

	while (42)
	{
		if (side_dist->x < side_dist->y)
		{
			side_dist->x += delta_dist->x;
			wall->map.x += wall->step.x;
			side = 0;
		}
		else
		{
			side_dist->y += delta_dist->y;
			wall->map.y += wall->step.y;
			side = 1;
		}
		if (info->map->map[wall->map.x][wall->map.y] == '1')
			return (side);
	}
}
