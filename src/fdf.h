/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:18:55 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/14 18:48:21 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>

# define KEY_ESC 65307

# define WIN_WIDTH 1600
# define WIN_HEIGHT 900
# define WIN_TITLE "FdF"

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
	t_data	img;
}			t_vars;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

void			init_vars(t_vars *vars);
void			init_hooks(t_vars *vars);
void			destroy_mlx(t_vars *vars);
int				quit_app(t_vars *vars);
int				key_press(int keycode, t_vars *vars);
int				window_resized(t_vars *vars);
int				mouse_enter(int x, int y, t_vars *vars);
int				mouse_exit(int x, int y, t_vars *vars);
void			put_rect(t_data *img, t_point pos, t_point size, int color);
void			put_pixel(t_data *img, int x, int y, int color);
void			draw_line(t_data *img, t_point point1, t_point point2,
					int color);
void			set_point(t_point *point, int x, int y);
int				get_trgb(int t, int r, int g, int b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);
int				ft_abs(int n);

#endif