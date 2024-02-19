/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:34:01 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/14 15:27:32 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)malloc(count * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	ft_identifier(char *str, int c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
