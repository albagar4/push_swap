/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:01:27 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/09 18:38:04 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// int	min_searching(t_stack **stack_a)
// {
// 	int	min;

// 	min = INT32_MAX;
// 	while ((*stack_a)->next)
// 	{
// 		if (((*stack_a)->value < min) && ((*stack_a)->index == -1))
// 			min = (*stack_a)->value;
// 		*stack_a = (*stack_a)->next;
// 	}
// 	while ((*stack_a)->next)
// 	{
// 		if ((*stack_a)->value == min)
// 			(*stack_a)->index = 1;
// 		*stack_a = (*stack_a)->next;
// 	}
// 	return (min);
// }

int	min_searching(t_stack *stack_a)
{
	int	min;
	t_stack	*start;

	min = INT32_MAX;
	start = stack_a;
	while ((stack_a)->next)
	{
		printf("estoy dando putas vueltas aqui????\n");
		printf("el min en esta puta vuelta: %i\n", stack_a->value);
		if ((stack_a)->value < min)
			min = (stack_a)->value;
		stack_a = (stack_a)->next;
	}
	// stack_a = start;
	// while ((stack_a)->next)
	// {
	// 	printf("y en este puto loop?????????\n");
	// 	if ((stack_a)->value == min)
	// 	{
	// 		(stack_a)->index = 1;
	// 		printf("el puto index: %i->%i\n", stack_a->value, stack_a->index);
	// 	}
	// 	stack_a = (stack_a)->next;
	// }
	return (min);
}

void	index_assign(t_stack **stack_a, int size)
{
	int		i;
	int		min;
	t_stack	*start;

	i = 2;
	min = min_searching(*stack_a);
	start = *stack_a;
	while ((*stack_a)->next)
	{
		if ((*stack_a)->value == min)
			(*stack_a)->index = 1;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = start;
	while (i <= size)
	{
		while ((*stack_a)->next)
		{
			if ((*stack_a)->index == -1)
			{
				if ((*stack_a)->value < min)
					min = (*stack_a)->value;
			}
			*stack_a = (*stack_a)->next;
		}
		*stack_a = start;
		while ((*stack_a)->next)
		{
			if ((*stack_a)->value == min)
				(*stack_a)->index = i;
			*stack_a = (*stack_a)->next;
		}
		*stack_a = start;
		i++;
	}
}
