/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:01:43 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/26 15:34:56 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <limits.h>

void	render_map(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j] != ULONG_MAX)
			render_and_put_pixel(vars, j, i, vars->map[i][j]);
	}
	mlx_put_image_to_window(vars->mlx->mlx, vars->mlx->win,
		vars->mlx->img, 0, 0);
}

void	render_point(t_vars *vars, t_point_3d *point)
{
	point->x = (point->x - vars->anchor_x) * vars->distance;
	point->y = (point->y - vars->anchor_y) * vars->distance;
	point->z = point->z * vars->height;
	rotate_x_y(vars, point);
	rotate_y_z(vars, point);
	rotate_z_x(vars, point);
	translate(vars, point);
	zoom(vars, point);
}

void	render_and_put_pixel(t_vars *vars, int x, int y, unsigned long data)
{
	t_point_3d	left_point;
	t_point_3d	top_point;
	t_point_3d	cur_point;

	set_point_3d(&cur_point, x, y, get_z(data));
	render_point(vars, &cur_point);
	if (x > 0)
	{
		set_point_3d(&left_point, x - 1, y, get_z(vars->map[y][x - 1]));
		render_point(vars, &left_point);
		draw_line(vars, (t_point){cur_point.x, cur_point.y},
			(t_point){left_point.x, left_point.y},
			get_color(vars->map[y][x - 1]));
	}
	if (y > 0)
	{
		set_point_3d(&top_point, x, y - 1, get_z(vars->map[y - 1][x]));
		render_point(vars, &top_point);
		draw_line(vars, (t_point){cur_point.x, cur_point.y},
			(t_point){top_point.x, top_point.y},
			get_color(vars->map[y - 1][x]));
	}
}
