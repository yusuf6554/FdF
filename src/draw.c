/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:48:06 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/26 14:50:13 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	int		i;
	char	*pixel;

	if ((WIN_WIDTH / 2) + x >= 0 && ft_abs((WIN_WIDTH / 2) + x)
		< WIN_WIDTH && WIN_HEIGHT / 2 - y >= 0
		&& WIN_HEIGHT / 2 - y < WIN_HEIGHT)
	{
		i = ((WIN_WIDTH / 2 + x) * vars->bits_per_pixel / 8)
			+ (WIN_HEIGHT / 2 + y) * vars->line_size;
		pixel = vars->data_addr + i;
		*(unsigned int *)pixel = color;
	}
}

void	draw_line(t_vars *vars, t_point point1, t_point point2,
	int color)
{
	int		step;
	double	x;
	double	y;
	int		i;

	x = point1.x;
	y = point1.y;
	step = ft_abs(point2.y - point1.y);
	if (ft_abs(point2.x - point1.x) > ft_abs(point2.y - point1.y))
		step = ft_abs(point2.x - point1.x);
	i = -1;
	while (++i <= step)
	{
		put_pixel(vars, (int)x, (int)y, color);
		x += (double)(point2.x - point1.x) / (double)step;
		y += (double)(point2.y - point1.y) / (double)step;
	}
}
