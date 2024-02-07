/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:01:27 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/07 18:58:07 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	index_assign(t_stack **stack_a, int size)
{
	int		i;
	int		min;
	t_stack	*start;

	i = 0;
	start = *stack_a;
	while (i++ <= size)
	{
		min = INT32_MAX;
		while (*stack_a)
		{
			if ((*stack_a)->index == -1)
				if ((*stack_a)->value < min)
					min = (*stack_a)->value;
			*stack_a = (*stack_a)->next;
		}
		*stack_a = start;
		while (*stack_a)
		{
			if ((*stack_a)->value == min)
				(*stack_a)->index = i;
			*stack_a = (*stack_a)->next;
		}
		*stack_a = start;
	}
}

void	position_control(t_stack **stack)
{
	int		i;
	t_stack	*start;

	i = 0;
	start = *stack;
	while (*stack)
	{
		(*stack)->pos = i;
		i++;
		*stack = (*stack)->next;
	}
	*stack = start;
}
