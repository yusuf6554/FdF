/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:48:24 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/14 15:17:21 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1600, 900, "Hello world!");
	(vars->img).img = mlx_new_image(vars->mlx, 1600, 900);
	(vars->img).addr = mlx_get_data_addr((vars->img).img,
			&(vars->img).bits_per_pixel,
			&(vars->img).line_length,
			&(vars->img).endian);
}

void	init_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 33, 1L << 17, quit_app, vars);
	mlx_key_hook(vars->win, key_press, vars);
	mlx_expose_hook(vars->win, window_resized, vars);
	mlx_hook(vars->win, 7, 1L << 4, mouse_enter, vars);
	mlx_hook(vars->win, 8, 1L << 5, mouse_exit, vars);
}

void	destroy_mlx(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, (vars->img).img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}
