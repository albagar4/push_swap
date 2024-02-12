/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:04:07 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/08 18:37:56 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_add_front(t_stack **stack, t_stack *node)
{
	node->next = *stack;
	*stack = node;
}

void	del_node(t_stack **stack)
{
	t_stack	*actual;

	if (!stack)
		return ;
	actual = (*stack)->next;
	free(*stack);
	*stack = actual;
	actual = 0;
}

t_stack	*stack_prelast(t_stack *stack)
{
	t_stack	*actual;

	if (!stack)
		return (0);
	actual = stack;
	while (actual->next->next)
		actual = actual->next;
	return (actual);
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*actual;

	if (!stack)
		return (0);
	actual = stack;
	while (actual->next)
		actual = actual->next;
	return (actual);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*actual;

	if (!(*stack))
		*stack = new;
	else
	{
		actual = stack_last(*stack);
		actual->next = new;
	}
}

t_stack	*pop_first(t_stack **stack)
{
	t_stack	*excluded;

	excluded = *stack;
	*stack = (*stack)->next;
	excluded->next = NULL;
	return (excluded);
}
