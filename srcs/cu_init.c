/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:12:39 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/12 21:05:14 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_mlx_window_img(t_info *info)
{
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "mlx");
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp,
			&info->img.size_l, &info->img.endian);
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	map->pp.x = 0;
	map->pp.y = 0;
	map->dir = 0;
	map->texture.cnt = 0;
	map->texture.ea_path = NULL;
	map->texture.no_path = NULL;
	map->texture.so_path = NULL;
	map->texture.we_path = NULL;
	map->texture.f_color[0] = -1;
	map->texture.c_color[0] = -1;
}

void	init_dir(t_info *info, t_map *map)
{
	if (map->dir == 'N')
	{
		info->dir.x = -1.0;
		info->plane.y = 0.66;
	}
	if (map->dir == 'S')
	{
		info->dir.x = 1.0;
		info->plane.y = -0.66;
	}
	if (map->dir == 'E')
	{
		info->dir.y = 1.0;
		info->plane.x = 0.66;
	}
	if (map->dir == 'W')
	{
		info->dir.y = -1.0;
		info->plane.x = -0.66;
	}
}

void	init_info(t_info *info, t_map *map)
{
	int	i;

	info->head = make_door_list(map);
	info->pos.x = map->pp.x + 0.51;
	info->pos.y = map->pp.y + 0.51;
	info->dir.x = 0;
	info->dir.y = 0;
	info->plane.x = 0.0;
	info->plane.y = 0.0;
	init_dir(info, map);
	info->re_buf = 0;
	info->pre_mouse_pos_x = 0;
	info->map = map;
	info->move_speed = 0.075;
	info->rot_speed = 0.075;
	info->mlx = mlx_init();
	i = 0;
	while (i < HEIGHT)
		ft_bzero(info->buf[i++], WIDTH);
	check_and_set_color(info, map, 'F');
	check_and_set_color(info, map, 'C');
}

void	check_and_set_color(t_info *info, t_map *map, char identifier)
{
	int		i;
	int		color;
	t_rgb	rgb;

	i = -1;
	while (++i < 3)
	{
		if (identifier == 'F')
			color = map->texture.f_color[i];
		else if (identifier == 'C')
			color = map->texture.c_color[i];
		if (!(color >= 0 && color <= 255))
			print_error_and_exit("color must in 255\n");
		if (i == 0)
			rgb.r = color;
		if (i == 1)
			rgb.g = color;
		if (i == 2)
			rgb.b = color;
	}
	if (identifier == 'F')
		info->floor_color = (rgb.r << 16 | rgb.g << 8 | rgb.b);
	else if (identifier == 'C')
		info->ceiling_color = (rgb.r << 16 | rgb.g << 8 | rgb.b);
}
