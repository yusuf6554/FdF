/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:28:33 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/18 13:26:20 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lines(t_data *img)
{
	t_point	start;
	t_point	end;

	set_point(&start, 100, 100);
	set_point(&end, 150, 170);
	draw_line(img, start, end, get_trgb(0, 255, 255, 255));
	set_point(&start, 200, 100);
	set_point(&end, 150, 170);
	draw_line(img, start, end, get_trgb(0, 255, 255, 255));
	set_point(&start, 150, 170);
	set_point(&end, 150, 300);
	draw_line(img, start, end, get_trgb(0, 255, 255, 255));
}

int	main(void)
{
	t_vars	vars;

	init_vars(&vars);
	draw_lines(&vars.img);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	init_hooks(&vars);
	mlx_loop(vars.mlx);
	destroy_mlx(&vars);
	return (0);
}
