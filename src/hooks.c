/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:32:06 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/14 18:55:29 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	quit_app(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_loop_end(vars->mlx);
	}
	return (0);
}

int	window_resized(t_vars *vars)
{
	static int	first_launch = 1;

	(void)vars;
	if (first_launch == 1)
		first_launch = 0;
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	mouse_enter(int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	(void)vars;
	return (0);
}

int	mouse_exit(int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	(void)vars;
	return (0);
}
