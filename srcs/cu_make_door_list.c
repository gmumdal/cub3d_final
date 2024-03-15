/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_make_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:59:41 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/11 20:58:15 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_door	*make_new_door(t_ipos pos);
static void		add_back_door(t_door *head, t_door *cur);

t_door	*make_door_list(t_map *map)
{
	t_door	*head;
	t_ipos	pos;

	head = NULL;
	pos.x = -1;
	while (++pos.x < map->height)
	{
		pos.y = -1;
		while (++pos.y < map->width)
		{
			if (map->map[pos.x][pos.y] == 'D')
			{
				if (head == NULL)
					head = make_new_door(pos);
				else
					add_back_door(head, make_new_door(pos));
				map->map[pos.x][pos.y] = '0';
			}
		}
	}
	return (head);
}

static t_door	*make_new_door(t_ipos pos)
{
	t_door	*cur;

	cur = (t_door *)ft_calloc(1, sizeof(t_door));
	cur->flag = 0;
	cur->open = 0;
	cur->dist = -1;
	cur->map.x = pos.x;
	cur->map.y = pos.y;
	cur->next = NULL;
	return (cur);
}

static void	add_back_door(t_door *head, t_door *cur)
{
	while (head->next != NULL)
		head = head->next;
	head->next = cur;
}
