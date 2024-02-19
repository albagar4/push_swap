/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:33:56 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/14 15:26:48 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../../include/ft_printf/libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*preserve_text(char *stash);
char	*update_stash(char	*stash, char *buffer);
char	*read_this_line(char *stash);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
int		ft_identifier(char *str, int c);

#endif
