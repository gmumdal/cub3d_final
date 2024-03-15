/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_door_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:51:03 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/12 13:34:20 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_door_order(t_info *info)
{
	t_door	*cur;
	int		i;

	cur = info->head;
	i = 0;
	while (cur != NULL)
	{
		cur->dist = pow(info->pos.x - cur->map.x, 2)
			+ pow(info->pos.y - cur->map.y, 2);
		cur = cur->next;
		i++;
	}
	return (i);
}

double	*sort_door_arr(t_info *info, int door_num)
{
	double	*arr;
	t_door	*cur;
	int		i;
	int		j;

	arr = (double *)ft_calloc(door_num, sizeof(double *));
	cur = info->head;
	i = 0;
	while (i < door_num)
	{
		arr[i++] = cur->dist;
		cur = cur->next;
	}
	i = -1;
	while (++i < door_num)
	{
		j = -1;
		while (++j < door_num - 1)
			swap_arr(arr, j);
	}
	return (arr);
}

void	swap_arr(double *arr, int j)
{
	double	tmp;

	if (arr[j] < arr[j + 1])
	{
		tmp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = tmp;
	}	
}

t_door	*find_i_door(t_info *info, double dist)
{
	t_door	*cur;

	cur = info->head;
	while (cur != NULL)
	{
		if (cur->dist == dist)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}
