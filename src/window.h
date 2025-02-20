/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:27:04 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/20 15:19:21 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define KEY_ESC 65307

# define WIN_WIDTH 1600
# define WIN_HEIGHT 900
# define PADDED_WIDTH 1440
# define PADDED_HEIGHT 810
# define WIN_TITLE "FdF"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_mlx;

#endif