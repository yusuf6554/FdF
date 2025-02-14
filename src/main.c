/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:28:33 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/14 15:18:36 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	gradient_loop(int *r, int *g, int *b)
{
	if (*r == 255 && *g < 255 && *b == 0)
		*g = *g + 1;
	if (*r > 0 && *g == 255 && *b == 0)
		*r = *r - 1;
	if (*r == 0 && *g == 255 && *b < 255)
		*b = *b + 1;
	if (*r == 0 && *g > 0 && *b == 255)
		*g = *g - 1;
	if (*r < 255 && *g == 0 && *b == 255)
		*r = *r + 1;
	if (*r == 255 && *g == 0 && *b > 0)
		*b = *b - 1;
}

void	draw_shapes(t_data *img)
{
	t_point	pos;
	t_point	rectsize;
	int		r;
	int		g;
	int		b;

	pos.x = 35;
	pos.y = 35;
	rectsize.x = 1;
	rectsize.y = 150;
	r = 255;
	g = 0;
	b = 0;
	while (pos.x < 1565)
	{
		gradient_loop(&r, &g, &b);
		put_rect(img, pos, rectsize, get_trgb(0, r, g, b));
		pos.x++;
	}
}

int	main(void)
{
	t_vars	vars;

	init_vars(&vars);
	draw_shapes(&vars.img);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	init_hooks(&vars);
	mlx_loop(vars.mlx);
	destroy_mlx(&vars);
	return (0);
}
