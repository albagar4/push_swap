/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:52:15 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/12 16:14:46 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b, char *msg)
{
	t_stack	*popped;

	// print_stack(stack_a, "stack_a antes");
	// print_stack(stack_b, "stack_b antes");
	popped = pop_first(stack_b);
	// print_stack(&popped, "popped");
	// print_stack(stack_b, "stack_b despues del popped");
	stack_add_front(stack_a, popped);
	printf("%s", msg);
// 	print_stack(stack_a, "stack_a después");
// 	print_stack(stack_b, "stack_b después");
}

void	swap(t_stack **stack_a, char *msg)
{
	t_stack	*first_pos;
	t_stack	*sec_pos;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first_pos = pop_first(stack_a);
	sec_pos = pop_first(stack_a);
	stack_add_front(stack_a, first_pos);
	stack_add_front(stack_a, sec_pos);
	printf("%s", msg);
}

void	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_pos_a;
	t_stack	*sec_pos_a;
	t_stack	*first_pos_b;
	t_stack	*sec_pos_b;

	if (!(*stack_a) || !(*stack_b) || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	first_pos_a = pop_first(stack_a);
	sec_pos_a = pop_first(stack_a);
	first_pos_b = pop_first(stack_b);
	sec_pos_b = pop_first(stack_b);
	stack_add_front(stack_a, first_pos_a);
	stack_add_front(stack_a, sec_pos_a);
	stack_add_front(stack_b, first_pos_b);
	stack_add_front(stack_b, sec_pos_b);
	printf("ss\n");
}
