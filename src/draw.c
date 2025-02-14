/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:48:06 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/14 15:55:23 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	if ((WIN_WIDTH / 2) + x >= 0 && ft_abs((WIN_WIDTH / 2) + x)
		< WIN_WIDTH && WIN_HEIGHT / 2 - y >= 0
		&& WIN_HEIGHT / 2 - y < WIN_HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	put_rect(t_data *img, t_point pos, t_point size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			put_pixel(img, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
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
	i = 0;
	while (i <= step)
	{
		put_pixel(&(vars->img), (int)x, (int)y, color);
		x += (double)(point2.x - point1.x) / (double)step;
		y += (double)(point2.y - point1.y) / (double)step;
		i++;
	}
}
