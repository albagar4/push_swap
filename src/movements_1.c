/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:38:35 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/15 13:38:37 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b, char *msg)
{
	t_stack	*popped;

	popped = pop_first(stack_b);
	stack_add_front(stack_a, popped);
	ft_printf("%s", msg);
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
	ft_printf("%s", msg);
}

void	swap_swap(t_stack **stack_a, t_stack **stack_b, char *msg)
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
	ft_printf("%s", msg);
}
