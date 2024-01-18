/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:08:06 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/18 16:03:29 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*first_push(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	t_stack	*start;

	i = 0;
	while (*stack_a && (i <= (size - 3)))
	{
		if (((*stack_a)->index < (size / 2)) && (i < (size / 2)))
		{
			push(stack_b, stack_a, "pb\n");
			start = *stack_a;
			i++;
		}
		else
			*stack_a = (*stack_a)->next;
	}
	*stack_a = start;
	while ((*stack_a)->next && (i < (size - 3)))
	{
		push(stack_b, stack_a, "pb\n");
		start = *stack_a;
		i++;
	}
	*stack_a = start;
	*stack_a = three_digits_sort(stack_a);
	return (*stack_b);
}
