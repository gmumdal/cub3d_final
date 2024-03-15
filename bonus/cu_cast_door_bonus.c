/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_cast_door_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:25 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/15 20:42:05 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	cast_door(t_info *info)
{
	t_wall		door;
	int			i;
	int			door_num;
	double		*arr;

	door.a = -1;
	door_num = check_door_order(info);
	arr = sort_door_arr(info, door_num);
	i = -1;
	while (++i < door_num)
		put_buf_individual(info, arr, i, &door);
	free(arr);
	close_door(info, &door);
}

void	put_buf_individual(t_info *info, double *arr, int i, t_wall *door)
{
	t_door	*cur;

	cur = find_i_door(info, arr[i]);
	info->map->map[cur->map.x][cur->map.y] = 'D';
	door->b = -1;
	while (++door->b < WIDTH)
	{
		calc_door_dist(info, door);
		if (info->map->map[door->map.x][door->map.y] == 'D')
			open_door(door, cur);
		else
			continue ;
		find_door_part(info, door);
		put_buf_door_line(info, door, cur);
	}
	info->map->map[cur->map.x][cur->map.y] = '0';
}

void	open_door(t_wall *door, t_door *cur)
{
	if (cur->flag == 0)
	{
		if (cur->dist <= 10
			&& cur->open < HEIGHT)
			cur->open += 25 / door->perp_wall_dist;
		if (cur->dist <= 10
			&& cur->open >= HEIGHT)
			cur->open = HEIGHT;
		if (cur->dist > 10 && cur->open > 0)
			cur->open -= 25 / door->perp_wall_dist;
		if (cur->open < 0)
			cur->open = 0;
		cur->flag = 1;
	}
}

void	close_door(t_info *info, t_wall *door)
{
	t_door	*cur;

	cur = info->head;
	while (cur != NULL)
	{
		if (cur->dist > 10 && cur->open > 0)
			cur->open -= 30 / door->perp_wall_dist;
		cur->flag = 0;
		cur = cur->next;
	}
}
