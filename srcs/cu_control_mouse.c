/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_control_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:56:19 by jongmlee          #+#    #+#             */
/*   Updated: 2024/01/12 21:02:47 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	control_mouse(int x, int y, t_info *info)
{
	int		dir;
	double	tmp_rot_speed;

	(void)y;
	tmp_rot_speed = info->rot_speed;
	dir = 0;
	if (x - info->pre_mouse_pos_x > 0)
		dir = K_AR_R;
	else if (x - info->pre_mouse_pos_x < 0)
		dir = K_AR_L;
	if (dir != 0)
		info->rot_speed /= 2;
	press_left_rotate_key(dir, info);
	press_right_rotate_key(dir, info);
	info->pre_mouse_pos_x = x;
	info->rot_speed = tmp_rot_speed;
	return (0);
}
