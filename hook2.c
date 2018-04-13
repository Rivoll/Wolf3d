/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 23:02:32 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/26 05:28:46 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		hook_after_val(t_data *data, int key)
{
	if (key == MENU_HIDE)
		after_val(data);
	return (0);
}

void	chose_hook(t_data *data, int key)
{
	if (key >= 0)
	{
		key_hook_r_left_right(key, data);
		key_hook_left_right(key, data);
		key_hook_stop_hit(key, data);
	}
}

int		exit_program(void)
{
	ft_putendl("Exit Program");
	exit(1);
	return (0);
}

int		key_hook(int key, t_data *data)
{
	chose_hook(data, key);
	if (key == ESC)
		ft_exit("Exit Program\n");
	if (key >= 0)
	{
		set_image_untextured(data);
		mlx_string_put(data->mlx, data->win, 20, 10, 0xB9121B, "exit = esc");
		hook_after_val(data, key);
	}
	return (0);
}
