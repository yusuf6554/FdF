/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:56:16 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/26 15:35:33 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_perspective(t_vars *vars)
{
	double	width_distance;
	double	height_distance;

	width_distance = (double)PADDED_WIDTH / (vars->line_length);
	height_distance = (double)PADDED_HEIGHT / (vars->line_count);
	vars->x_y_coef = 0;
	vars->y_z_coef = -1;
	vars->z_x_coef = 0.3;
	vars->zoom = 1;
	vars->map_x = 0;
	vars->map_y = 0;
	vars->height = 5;
	if (width_distance > height_distance)
		vars->distance = height_distance;
	else
		vars->distance = width_distance;
}
