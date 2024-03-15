/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_check_key_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:48:37 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/15 20:42:02 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int	press_key(int key, t_info *info)
{
	if (key == K_ESC || key == X_EVENT_KEY_EXIT)
	{
		ending_free(info);
		exit(0);
	}
	press_front_back_key(key, info);
	press_left_right_key(key, info);
	press_left_rotate_key(key, info);
	press_right_rotate_key(key, info);
	mlx_clear_window(info->mlx, info->win);
	rendering(info);
	return (0);
}

void	press_front_back_key(int key, t_info *info)
{
	if (key == K_W)
	{
		if (info->map->map[(int)(info->pos.x + info->dir.x * info->move_speed)]
			[(int)(info->pos.y)] != '1')
			info->pos.x += info->dir.x * info->move_speed;
		if (info->map->map[(int)(info->pos.x)]
			[(int)(info->pos.y + info->dir.y * info->move_speed)] != '1')
			info->pos.y += info->dir.y * info->move_speed;
	}
	if (key == K_S)
	{
		if (info->map->map[(int)(info->pos.x - info->dir.x * info->move_speed)]
			[(int)(info->pos.y)] != '1')
			info->pos.x -= info->dir.x * info->move_speed;
		if (info->map->map[(int)(info->pos.x)]
			[(int)(info->pos.y - info->dir.y * info->move_speed)] != '1')
			info->pos.y -= info->dir.y * info->move_speed;
	}
}

void	press_left_right_key(int key, t_info *info)
{
	if (key == K_A)
	{
		if (info->map->map[(int)(info->pos.x - info->dir.y * info->move_speed)]
			[(int)(info->pos.y)] != '1')
			info->pos.x -= info->dir.y * info->move_speed;
		if (info->map->map[(int)(info->pos.x)]
			[(int)(info->pos.y + info->dir.x * info->move_speed)] != '1')
			info->pos.y += info->dir.x * info->move_speed;
	}
	if (key == K_D)
	{
		if (info->map->map[(int)(info->pos.x + info->dir.y * info->move_speed)]
			[(int)(info->pos.y)] != '1')
			info->pos.x += info->dir.y * info->move_speed;
		if (info->map->map[(int)(info->pos.x)]
			[(int)(info->pos.y - info->dir.x * info->move_speed)] != '1')
			info->pos.y -= info->dir.x * info->move_speed;
	}
}

void	press_left_rotate_key(int key, t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key == K_AR_L)
	{
		old_dir_x = info->dir.x;
		info->dir.x = info->dir.x * cos(info->rot_speed)
			- info->dir.y * sin(info->rot_speed);
		info->dir.y = old_dir_x * sin(info->rot_speed)
			+ info->dir.y * cos(info->rot_speed);
		old_plane_x = info->plane.x;
		info->plane.x = info->plane.x * cos(info->rot_speed)
			- info->plane.y * sin(info->rot_speed);
		info->plane.y = old_plane_x * sin(info->rot_speed)
			+ info->plane.y * cos(info->rot_speed);
	}
}

void	press_right_rotate_key(int key, t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key == K_AR_R)
	{
		old_dir_x = info->dir.x;
		info->dir.x = info->dir.x * cos(-info->rot_speed)
			- info->dir.y * sin(-info->rot_speed);
		info->dir.y = old_dir_x * sin(-info->rot_speed)
			+ info->dir.y * cos(-info->rot_speed);
		old_plane_x = info->plane.x;
		info->plane.x = info->plane.x * cos(-info->rot_speed)
			- info->plane.y * sin(-info->rot_speed);
		info->plane.y = old_plane_x * sin(-info->rot_speed)
			+ info->plane.y * cos(-info->rot_speed);
	}
}
