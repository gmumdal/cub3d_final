/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cu_load_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:41:39 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/15 20:42:02 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	a;
	int	b;

	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
	a = -1;
	while (++a < img->img_height)
	{
		b = -1;
		while (++b < img->img_width)
			texture[img->img_width * a + b] = img->data[img->img_width * a + b];
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], info->map->texture.no_path, &img);
	load_image(info, info->texture[1], info->map->texture.so_path, &img);
	load_image(info, info->texture[2], info->map->texture.we_path, &img);
	load_image(info, info->texture[3], info->map->texture.ea_path, &img);
	load_image(info, info->texture[4], "textures/door.xpm", &img);
}
