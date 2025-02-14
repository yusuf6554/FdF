/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:32:06 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/14 13:37:37 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	quit_app(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
		ft_putendl_fd("Key pressed", 1);
}

int	window_resized(t_vars *vars)
{
	static int	first_launch = 1;

	if (first_launch == 1)
		first_launch = 0;
	else
		ft_putendl_fd("Window resized", 1);
}

int	mouse_enter(int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	ft_putendl_fd("Hello!", 1);
}

int	mouse_exit(int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	ft_putendl_fd("Bye!", 1);
}
