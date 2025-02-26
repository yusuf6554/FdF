/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:05:20 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/26 15:00:43 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char	*ft_read_map_file(char *map_filename)
{
	int		fd;
	char	*map;
	char	*line;
	int		ret;

	fd = open(map_filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret = 1;
	map = NULL;
	while (ret)
	{
		line = malloc(BUFFER_SIZE + 1);
		if (!line)
			return (mem_and_read_error_func(map, 1));
		ret = read(fd, line, BUFFER_SIZE);
		if (ret < 0)
			return (mem_and_read_error_func(map, 2));
		line[ret] = '\0';
		map = ft_strjoin(map, line);
		if (!map)
			return (mem_and_read_error_func(NULL, 1));
	}
	return (map);
}

unsigned long	ft_proc_map_pts(char *pt)
{
	char			**pts;
	int				z;
	unsigned long	color;
	unsigned long	res;

	pts = ft_split(pt, ',');
	if (!pts)
		return (ULONG_MAX);
	z = ft_atoi(pts[0]);
	if (!pts[1])
		color = DEFAULT_COLOR;
	else
		color = ft_atoi_base_16(pts[1] + 2);
	res = (unsigned long)z << 32 | color;
	ft_free_split(pts);
	return (res);
}

unsigned long	*ft_line_to_array(char *line)
{
	size_t			i;
	char			**pts;
	size_t			len;
	unsigned long	*res;

	pts = ft_split(line, ' ');
	if (!pts)
		return (NULL);
	len = ft_array_len((unsigned long *)pts);
	res = malloc(sizeof(unsigned long) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (pts[++i])
		res[i] = ft_proc_map_pts(pts[i]);
	res[len] = ULONG_MAX;
	ft_free_split(pts);
	return (res);
}

unsigned long	**ft_map_to_full_array(char *file)
{
	char			**lines;
	unsigned long	**res;
	int				i;
	size_t			len;

	lines = ft_split(file, '\n');
	if (!lines)
		return (NULL);
	len = ft_array_len((unsigned long *)lines);
	res = malloc(sizeof(unsigned long *) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (lines[++i])
		res[i] = ft_line_to_array(lines[i]);
	res[len] = NULL;
	ft_free_split(lines);
	return (res);
}
