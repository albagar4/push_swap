/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:18:47 by albagar4          #+#    #+#             */
/*   Updated: 2023/11/23 17:17:21 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

int		count_numbers(char *str);
long	*one_argument(char *string, int *size);
long	*multiple_arguments(char **str, int *size);
int		nbr_checker(long *nbr_array, int size);
t_stack	*create_node(long nbr);
t_stack	*arr_to_list(long *stack, int size);
int		push_x(t_stack *stack_dst, t_stack *stack_src);
#endif