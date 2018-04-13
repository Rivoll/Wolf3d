/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 23:02:02 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/25 05:32:56 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			color_map(t_data *data)
{
	int		color;

	color = 0x000000;
	if (data->side == 0 && data->ray_dir_x > 0)
		color = 0xaa1111;
	if (data->side == 0 && data->ray_dir_x < 0)
		color = 0x16B84E;
	if (data->side == 1 && data->ray_dir_y > 0)
		color = 0x03224C;
	if (data->side == 1 && data->ray_dir_y < 0)
		color = 0x600060;
	return (color);
}

void		print_map(t_data *data, int x)
{
	int		i;
	int		color;

	i = -1;
	color = color_map(data);
	while (++i < WIDTH)
		set_pixel(x, i, 0xFEBFD2, data);
	i = -1;
	while (++i < (data->draw_end - data->draw_start))
		set_pixel(x, i + data->draw_start, color, data);
	i = data->draw_end - 1;
	while (++i < HEIGHT)
	{
		set_pixel(x, i, 0xffffff - i / 3, data);
	}
}

void		set_image_untextured(t_data *data)
{
	data->img = mlx_new_image(data->mlx, (int)WIDTH, (int)HEIGHT);
	data->pixel = mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
	untextured(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}

void		calc_height_line(t_data *data)
{
	data->perp_wall_dis = (data->side == 0) ? (data->map_x - data->ray_pos_x +
			(1 - data->step_x) / 2) / data->ray_dir_x : (data->map_y -
				data->ray_pos_y + (1 - data->step_y) / 2) / data->ray_dir_y;
	data->line_height = (int)(HEIGHT / data->perp_wall_dis);
	data->draw_start = -(data->line_height) / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = HEIGHT / 2 + data->line_height / 2;
	if (data->draw_start >= HEIGHT)
		data->draw_end = HEIGHT - 1;
}
