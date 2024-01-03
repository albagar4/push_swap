/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:18:47 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/03 11:28:52 by albagar4         ###   ########.fr       */
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
int		push_x(t_stack **stack_dst, t_stack *stack_src);
void	print_stack(t_stack *stack);
void	del_node(t_stack **stack);
void	stack_add_front(t_stack **stack, t_stack *node);
t_stack	*stack_last(t_stack *lst);
void	stack_add_back(t_stack **stack, t_stack *new);
void	checker(t_stack *stack_a, t_stack *stack_b);
#endif