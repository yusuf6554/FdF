/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:32:06 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/20 15:07:10 by yukoc            ###   ########.fr       */
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
	if (keycode == 65307)
	{
		mlx_loop_end(vars->mlx->mlx);
	}
	return (0);
}
