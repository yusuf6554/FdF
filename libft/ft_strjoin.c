/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:18:04 by yukoc             #+#    #+#             */
/*   Updated: 2025/02/18 13:28:37 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str_final;
	size_t		len1;
	size_t		len2;

	if (!s1 || !s2)
	{
		if (!s1)
			return (s2);
		return (s1);
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str_final = malloc(sizeof(char) * (len1 + len2 + 1));
	if (str_final == NULL)
		return (NULL);
	ft_strlcpy(str_final, s1, len1 + 1);
	ft_strlcpy(str_final + len1, s2, len2 + 1);
	free(s1);
	free(s2);
	return (str_final);
}
