/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:15:57 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/26 14:59:13 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

size_t	ft_array_len(unsigned long *arr)
{
	size_t	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

unsigned int	ft_atoi_base_16(char *str)
{
	unsigned int	res;
	int				i;

	res = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 16 + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res * 16 + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res * 16 + str[i] - 'a' + 10;
	}
	return (res);
}

char	*mem_and_read_error_func(char *str, int error)
{
	if (str)
		free(str);
	if (error == 1)
		write(STDERR_FILENO, "Memory allocation failed", 24);
	else if (error == 2)
		write(STDERR_FILENO, "Read error", 10);
	return (NULL);
}
