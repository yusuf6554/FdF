/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:18:55 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/14 13:52:36 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

int				quit_app(t_vars *vars);
int				key_press(int keycode, t_vars *vars);
int				window_resized(t_vars *vars);
int				mouse_enter(int x, int y, t_vars *vars);
int				mouse_exit(int x, int y, t_vars *vars);
void			put_square(t_data *img, t_point pos, int size, int color);
void			put_circle(t_data *img, t_point pos, int radius, int color);
void			put_hexagon(t_data *img, t_point pos, int size, int color);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				get_trgb(int t, int r, int g, int b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

#endif