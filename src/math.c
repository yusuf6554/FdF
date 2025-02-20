/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:28:11 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/20 14:19:51 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	set_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

void	set_point_3d(t_point_3d *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

unsigned long	get_z(unsigned long data)
{
	return (data >> 32);
}

unsigned long	get_color(unsigned long data)
{
	return (data & COLOR_MASK);
}
