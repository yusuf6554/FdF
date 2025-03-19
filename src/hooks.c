/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:32:06 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/19 03:42:31 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	quit_app(t_vars *vars)
{
	mlx_loop_end(vars->mlx->mlx);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(vars->mlx->mlx);
	}
	else
	{
		mlx_put_image_to_window(vars->mlx->mlx, vars->mlx->win,
			vars->mlx->img, 0, 0);
	}
	return (0);
}
