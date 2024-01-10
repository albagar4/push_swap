/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:18:47 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/10 17:53:06 by albagar4         ###   ########.fr       */
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

void	push(t_stack **stack_a, t_stack **stack_b, char *msg);
void	swap(t_stack **stack_a, char *msg);
void	rotate(t_stack **stack, char *msg);
void	reverse_rotate(t_stack **stack, char *msg);
void	swap_swap(t_stack **stack_a, t_stack **stack_b);
void	rotate_rotate(t_stack **stack_1, t_stack **stack_2);
void	reverse_rotate_rotate(t_stack **stack_1, t_stack **stack_2);

void	print_stack(t_stack **stack, char *name);
void	print_index(t_stack **stack, char *name);
void	print_pos(t_stack **stack, char *name);
void	print_node(t_stack *stack, char *name);

void	del_node(t_stack **stack);
void	stack_add_front(t_stack **stack, t_stack *node);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_prelast(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*copy_node(t_stack *node);
void	checker(t_stack *stack_a, t_stack *stack_b);
t_stack	*pop_first(t_stack **stack);

void	index_assign(t_stack **stack_a, int size);
void	position_control(t_stack **stack);

t_stack	*two_digits_sort(t_stack **stack);
t_stack	*three_digits_sort(t_stack **stack);
#endif