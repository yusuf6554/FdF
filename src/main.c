/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:28:33 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/26 15:43:54 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

void	fdf_main(t_vars *vars)
{
	mlx_hook(vars->mlx->win, 33, 1L << 17, quit_app, vars);
	mlx_key_hook(vars->mlx->win, key_press, vars);
	set_perspective(vars);
	render_map(vars);
	mlx_loop(vars->mlx->mlx);
}

void	set_map_properties(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[0][i] != ULONG_MAX)
		i++;
	vars->line_length = i;
	vars->anchor_x = i / 2;
	i = 0;
	while (vars->map[i] != NULL)
		i++;
	vars->line_count = i;
	vars->anchor_y = i / 2;
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_mlx	mlx;
	char	*map_str;

	if (argc != 2)
		return (return_error(1));
	map_str = ft_read_map_file(argv[1]);
	if (!map_str)
		return (return_error(2));
	vars.map = ft_map_to_full_array(map_str);
	if (!vars.map)
		return (return_error(3));
	free(map_str);
	set_map_properties(&vars);
	vars.mlx = &mlx;
	if (init_vars(&vars) == 1)
		return (return_error(4));
	fdf_main(&vars);
	destroy_mlx(&mlx);
	free(mlx.mlx);
	ft_free_map(vars.map);
	return (0);
}
