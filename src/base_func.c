/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:48:24 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/10 13:54:04 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

int	init_vars(t_vars *vars)
{
	vars->mlx->mlx = mlx_init();
	if (!vars->mlx->mlx)
		return (1);
	vars->mlx->win = mlx_new_window(vars->mlx->mlx, WIN_WIDTH, WIN_HEIGHT,
			WIN_TITLE);
	if (!vars->mlx->win)
	{
		mlx_destroy_display(vars->mlx->mlx);
		free(vars->mlx->mlx);
		return (1);
	}
	vars->mlx->img = mlx_new_image(vars->mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!vars->mlx->img)
	{
		mlx_destroy_window(vars->mlx->mlx, vars->mlx->win);
		mlx_destroy_display(vars->mlx->mlx);
		free(vars->mlx->mlx);
		return (1);
	}
	vars->data_addr = mlx_get_data_addr(vars->mlx->img, &vars->bits_per_pixel,
			&vars->line_size, &vars->endian);
	return (0);
}

void	destroy_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
}
