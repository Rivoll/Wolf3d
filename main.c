/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 23:02:53 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/26 05:39:46 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_pixel(int x, int y, int color, t_data *data)
{
	int		index;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		index = (y * data->size_line) + (x * data->bpp / 8);
		data->pixel[index] = (color & 0xFF);
		data->pixel[index + 1] = (color & 0xFF00) >> 8;
		data->pixel[index + 2] = (color & 0xFF0000) >> 16;
	}
}

void		init(t_data *data)
{
	data->pos_x = 11.5;
	data->pos_y = 4.5;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->hit = 0;
	data->rot = M_PI / (double)25;
	data->speed = 0.1;
}

void		after_val(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 20, 780, 0xffffff, "Menu");
	mlx_string_put(data->mlx, data->win, 20, 820, 0xffffff, "Move :");
	mlx_string_put(data->mlx, data->win, 20, 840, 0xffffff, "RIGHT = right");
	mlx_string_put(data->mlx, data->win, 20, 860, 0xffffff, "LEFT  = left");
	mlx_string_put(data->mlx, data->win, 20, 880, 0xffffff, "FRONT = up");
	mlx_string_put(data->mlx, data->win, 20, 900, 0xffffff, "BACK  = down");
}

int			main(void)
{
	t_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "wolf3d");
	init(&data);
	set_image_untextured(&data);
	after_val(&data);
	mlx_hook(data.win, 17, 18, exit_program, &data);
	mlx_hook(data.win, 2, 3, key_hook, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img);
	return (0);
}
