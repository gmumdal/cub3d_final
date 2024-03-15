/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:55:32 by hyeongsh          #+#    #+#             */
/*   Updated: 2024/01/12 21:07:40 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "keys.h"
# include "libft.h"
# include "get_next_line_bonus.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define X_EVENT_MOUSE 6
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define WIDTH 640
# define HEIGHT 480
# define MINIMAP_SCALE 0.3
# define MINIMAP_UNIT 12
# define MAP_PATH "map/"
# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define F 5
# define C 6

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_ipos
{
	int	x;
	int	y;
}	t_ipos;

typedef struct s_dpos
{
	double	x;
	double	y;
}	t_dpos;

typedef struct s_texture
{
	int		cnt;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		c_color[3];
	int		f_color[3];
}	t_texture;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	char		dir;
	t_ipos		pp;
	t_texture	texture;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_door
{
	t_ipos			map;
	int				open;
	int				flag;
	double			dist;
	struct s_door	*next;
}	t_door;

typedef struct s_info
{
	t_dpos		pos;
	t_dpos		dir;
	t_dpos		plane;
	t_map		*map;
	int			pre_mouse_pos_x;
	char		minimap[MINIMAP_UNIT][MINIMAP_UNIT];
	void		*mlx;
	void		*win;
	t_img		img;
	int			buf[HEIGHT][WIDTH];
	int			texture[5][TEX_HEIGHT * TEX_WIDTH];
	double		move_speed;
	double		rot_speed;
	int			re_buf;
	int			ceiling_color;
	int			floor_color;
	t_door		*head;
}	t_info;

typedef struct s_wall
{
	t_ipos	step;
	t_dpos	ray_dir;
	t_ipos	map;
	double	perp_wall_dist;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	ratio;
	t_ipos	tex;
	int		a;
	int		b;
}	t_wall;

/* cub3d.c */
void	get_map(t_map *map, char *map_path);
int		rendering(t_info *info);
void	draw(t_info *info);
int		close_mlx_window(void *param);

/* cu_load_data */
void	load_image(t_info *info, int *texture, char *path, t_img *img);
void	load_texture(t_info *info);

/* cu_check_key */
int		press_key(int key, t_info *info);
void	press_front_back_key(int key, t_info *info);
void	press_left_right_key(int key, t_info *info);
void	press_left_rotate_key(int key, t_info *info);
void	press_right_rotate_key(int key, t_info *info);

/* cu_cast_floor */
void	cast_floor(t_info *info);

/* cu_cast_wall_utils.c */
void	find_draw_part(t_info *info, t_wall *wall);
int		get_wall_color(t_info *info, t_wall *wall);
void	put_buf_wall_line(t_info *info, t_wall *wall);

/* cu_cast_wall.c */
void	cast_wall(t_info *info);
void	calc_wall_dist(t_info *info, t_wall *wall);
int		hit_wall(t_info *info, t_wall *wall);
int		check_hit_wall(t_dpos *side_dist, t_dpos *delta_dist,
			t_wall *wall, t_info *info);

/* cu_parse_utils.c */
void	check_map_name(char *map_name);
int		is_map_element(char c);
void	is_valid_path(int identifier, char *path, t_map *map);
void	is_duplicated_path(int identifier, char *path, t_map *map);

/* cu_parse_texture.c */
void	set_texture_path(t_map *map, char *line);
void	get_texture(t_map *map, int fd);
void	load_file(char *map_path, t_map *map);

/* cu_texture_utils.c */
int		is_texture_identifier(char *line);
int		is_texture_element(char *line);
void	check_color_is_valid(t_map *map, char *line, char identifier);
void	trim_textures(t_texture *texture);

/* cu_parse_map_utils.c */
int		is_map_element_arr(char *line);
void	check_map_is_surrouned(t_map *map, int h, int w);
void	check_map_is_valid(t_map *map);
void	check_door_is_surrounded(t_map *map, int x, int y);
char	*move_to_map_element(int fd);

/* cu_parse_map.c */
void	set_map_width_height(t_map *map, int fd);
void	set_map_width(t_map *map, char *line);
void	pre_set_map(t_map *map);
void	set_map_component(t_map *map, char *line,
			int height_cnt, int *pos_flag);
void	set_map_elements(t_map *map, char *map_path);

/* cu_utils.c */
void	print_error_and_exit(char *message);
void	free_2d_array(char **arr);
int		get_str_2d_len(char **s);
void	ending_free(t_info *info);

/* cu_debug.c */
void	print_texture_struct(t_texture texture);
void	print_map_struct(t_map *map);
void	print_2d_arr(char **s, int arr_cnt);
void	print_2d_arr_d(char **s, int arr_cnt);

/* cu_init.c */
void	init_map(t_map *map);
void	init_info(t_info *info, t_map *map);
void	check_and_set_color(t_info *info, t_map *map, char identifier);
void	init_mlx_window_img(t_info *info);

/* cu_draw_minimap.c */
void	draw_minimap(t_info *info);
int		get_map_idx(int n, int len);
void	set_minimap(t_info *info);

/* cu_control_mouse.c */
int		control_mouse(int x, int y, t_info *info);

/* cu_cast_door.c */
void	cast_door(t_info *info);
void	calc_door_dist(t_info *info, t_wall *door);
void	open_door(t_wall *door, t_door *cur);
void	close_door(t_info *info, t_wall *door);
void	put_buf_individual(t_info *info, double *arr, int i, t_wall *door);

/* cu_make_door_list.c */
t_door	*make_door_list(t_map *map);

/* cu_check_hit_door.c */
void	calc_door_dist(t_info *info, t_wall *door);
int		hit_door(t_info *info, t_wall *door);
int		check_hit_door(t_dpos *side_dist, t_dpos *delta_dist,
			t_wall *door, t_info *info);
void	find_door_part(t_info *info, t_wall *door);
void	put_buf_door_line(t_info *info, t_wall *door, t_door *cur);

/* cu_door_utils.c */
int		check_door_order(t_info *info);
double	*sort_door_arr(t_info *info, int door_num);
void	swap_arr(double *arr, int j);
t_door	*find_i_door(t_info *info, double dist);

#endif
