/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 01:41:13 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/26 01:41:15 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft/include/libft.h"
# include <mlx.h>
# include <math.h>
# define WIDTH 812
# define HEIGHT 684
# define UP 126
# define DOWN 125
# define RIGHT 2
# define LEFT 0
# define ESC 53
# define R_RIGHT 124
# define R_LEFT 123
# define MENU_HIDE 4

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pixel;

	int				x;
	int				y;

	double			pos_x;
	double			pos_y;

	double			dir_x;
	double			dir_y;

	double			plane_x;
	double			plane_y;

	double			ray_pos_x;
	double			ray_pos_y;

	double			ray_dir_x;
	double			ray_dir_y;

	double			cam_x;

	int				map_x;
	int				map_y;

	double			delta_dis_x;
	double			delta_dis_y;

	int				step_x;
	int				step_y;

	double			side_dis_x;
	double			side_dis_y;

	int				hit;

	int				side;

	double			perp_wall_dis;

	double			line_height;

	int				draw_start;
	int				draw_end;

	int				size_line;
	int				bpp;
	int				endian;
	int				color;

	double			rot;
	double			speed;

	double			t_d;
	double			t_p;

	double			wall_x;
}					t_data;

int					exit_program(void);
void				calc_height_line(t_data *data);
void				after_val(t_data *data);
int					hook_after_val(t_data *data, int key);
int					key_hook_left_right(int key, t_data *data);
int					key_hook_r_left_right(int key, t_data *data);
int					key_hook_stop_hit(int key, t_data *data);
int					key_hook(int key, t_data *data);
void				set_pixel(int x, int y, int color, t_data *data);
int					map_untextured(int x, int y);
void				untextured(t_data *data);
void				set_image_untextured(t_data *data);
void				print_map(t_data *data, int x);
void				ray_pos(t_data *data, int x);
void				init(t_data *data);
void				err_exit(char *str, t_data data);
void				usage(void);

#endif
