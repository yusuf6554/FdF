/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:28:33 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/14 13:54:16 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_point	pos;

	vars.mlx = mlx_init();
	img.img = mlx_new_image(vars.mlx, 1600, 900);
	vars.win = mlx_new_window(vars.mlx, 1600, 900, "Hello world!");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	pos.x = 100;
	pos.y = 100;
	put_square(&img, pos, 100, get_trgb(0, 255, 255, 255));
	pos.x = 500;
	put_circle(&img, pos, 100, get_trgb(0, 255, 0, 0));
	pos.x = 900;
	put_hexagon(&img, pos, 100, get_trgb(0, 0, 255, 0));
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 33, 1L << 17, quit_app, &vars);
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_expose_hook(vars.win, window_resized, &vars);
	mlx_hook(vars.win, 7, 1L << 4, mouse_enter, &vars);
	mlx_hook(vars.win, 8, 1L << 5, mouse_exit, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
