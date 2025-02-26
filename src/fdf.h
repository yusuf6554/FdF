/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:18:55 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/26 15:45:34 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "window.h"
# include <stddef.h>

# define BUFFER_SIZE 50000
# define COLOR_MASK 0xFFFFFFFFU
# define DEFAULT_COLOR 0x00FFFFFF

typedef struct s_vars
{
	t_mlx			*mlx;
	unsigned long	**map;
	char			*data_addr;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	int				map_x;
	int				map_y;
	double			x_y_coef;
	double			y_z_coef;
	double			z_x_coef;
	double			zoom;
	double			distance;
	double			height;
	int				line_length;
	int				line_count;
	int				anchor_x;
	int				anchor_y;
}			t_vars;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_point_3d
{
	int	x;
	int	y;
	int	z;
}			t_point_3d;

int				init_vars(t_vars *vars);
void			destroy_mlx(t_mlx *mlx);

int				quit_app(t_vars *vars);
int				key_press(int keycode, t_vars *vars);

void			put_pixel(t_vars *vars, int x, int y, int color);
void			draw_line(t_vars *vars, t_point point1, t_point point2,
					int color);

int				ft_abs(int n);
void			set_point(t_point *point, int x, int y);
void			set_point_3d(t_point_3d *point, int x, int y, int z);
unsigned long	get_z(unsigned long data);
unsigned long	get_color(unsigned long data);

void			ft_free_split(char **split);
void			ft_free_map(unsigned long **map);

size_t			ft_array_len(unsigned long *arr);
unsigned int	ft_atoi_base_16(char *str);
char			*mem_and_read_error_func(char *str, char *str2, int error);
int				return_error(int error);

char			*ft_read_map_file(char *map_filename);
unsigned long	ft_proc_map_pts(char *pt);
unsigned long	*ft_line_to_array(char *line);
unsigned long	**ft_map_to_full_array(char *file);

void			set_perspective(t_vars *vars);

void			zoom(t_vars *vars, t_point_3d *point);
void			translate(t_vars *vars, t_point_3d *point);
void			rotate_z_x(t_vars *vars, t_point_3d *point);
void			rotate_y_z(t_vars *vars, t_point_3d *point);
void			rotate_x_y(t_vars *vars, t_point_3d *point);

void			render_map(t_vars *vars);
void			render_point(t_vars *vars, t_point_3d *point);
void			render_and_put_pixel(t_vars *vars, int x, int y,
					unsigned long data);

#endif