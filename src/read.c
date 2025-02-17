/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:05:20 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/17 17:19:18 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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
	map = ft_strdup("");
	while (ret)
	{
		line = malloc(BUFFER_SIZE + 1);
		if (!line)
			return (free(map), write(STDERR_FILENO,
				"Memory allocation failed", 24), NULL);
		ret = read(fd, line, BUFFER_SIZE);
		if (ret < 0)
			return (free(map), write(STDERR_FILENO, "Read error", 18), NULL);
		line[ret] = '\0';
		map = ft_strjoin(map, line);
		if (!map)
			return (write(STDERR_FILENO, "Memory allocation failed", 24), NULL);
	}
	return (map);
}
