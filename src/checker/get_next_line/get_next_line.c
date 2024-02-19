/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:34:05 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/14 15:26:57 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*preserve_text(char *stash)
{
	int		length;
	int		i;
	int		j;
	char	*rest;

	i = 0;
	if (ft_identifier(stash, '\n') == -1)
	{
		if (!stash)
			return (NULL);
		return (free(stash), NULL);
	}
	length = (ft_strlen(stash) - ft_identifier(stash, '\n') + 1);
	j = ft_identifier(stash, '\n') + 1;
	rest = ft_calloc(length, sizeof(char));
	if (!rest)
		return (NULL);
	while (j < (int)ft_strlen(stash))
		rest[i++] = stash[j++];
	rest[i] = '\0';
	if (rest[0] == '\0')
		return (free(rest), free(stash), NULL);
	return (free(stash), rest);
}

char	*update_stash(char	*stash, char *buffer)
{
	char	*new_stash;

	if (!stash)
	{
		new_stash = ft_strdup(buffer);
		if (!new_stash)
			return (NULL);
	}
	else
	{
		new_stash = ft_strjoin(stash, buffer);
		free(stash);
	}
	return (new_stash);
}

char	*read_this_line(char *stash)
{
	int		i;
	int		length;
	char	*line;

	length = ft_identifier(stash, '\n');
	if (length == -1)
	{
		if (stash)
		{
			line = ft_strdup(stash);
			return (line);
		}
		return (NULL);
	}
	i = 0;
	line = ft_calloc(length + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (i <= length)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	free_stash(char *stash)
{
	if (stash)
		free(stash);
	stash = NULL;
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*buffer;
	char		*line;
	int			numbytes;

	numbytes = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (free_stash(stash), NULL);
	while (ft_identifier(stash, '\n') == -1 && numbytes > 0)
	{
		numbytes = read(fd, buffer, BUFFER_SIZE);
		if (numbytes == 0)
			break ;
		if (numbytes == -1)
			return (free_stash(stash), free(buffer), NULL);
		buffer[numbytes] = 0;
		stash = update_stash(stash, buffer);
		if (!stash)
			return (NULL);
	}
	line = read_this_line(stash);
	stash = preserve_text(stash);
	return (free(buffer), line);
}
