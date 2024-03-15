/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:18:03 by yohlee            #+#    #+#             */
/*   Updated: 2024/01/12 21:05:31 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_info	info;

	if (ac != 2)
	{
		print_error_and_exit("need one map file\n");
		return (1);
	}
	check_map_name(av[1]);
	load_file(av[1], &map);
	init_info(&info, &map);
	load_texture(&info);
	init_mlx_window_img(&info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &press_key, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, &close_mlx_window, &info);
	mlx_hook(info.win, X_EVENT_MOUSE, 0, &control_mouse, &info);
	mlx_loop_hook(info.mlx, &rendering, &info);
	mlx_loop(info.mlx);
}

void	get_map(t_map *map, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("file open error\n");
	set_map_width_height(map, fd);
	set_map_elements(map, map_path);
	check_map_is_valid(map);
}

void	draw(t_info *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int	rendering(t_info *info)
{
	cast_floor(info);
	cast_wall(info);
	cast_door(info);
	draw_minimap(info);
	draw(info);
	return (1);
}

int	close_mlx_window(void *param)
{
	(void) param;
	exit(0);
}
