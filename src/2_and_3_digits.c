/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_and_3_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:04:56 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/10 17:57:49 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*two_digits_sort(t_stack **stack)
{
	if (((*stack)->next)->value < (*stack)->value)
		swap(stack, "sa\n");
	return (*stack);
}

t_stack	*three_digits_sort(t_stack **stack)
{
	index_assign(stack, 3);
	if ((*stack)->index == 1)
	{
		if (((*stack)->next->next)->index > ((*stack)->next)->index)
			return (*stack);
		return (reverse_rotate(stack, "rra\n"), swap(stack, "sa\n"), *stack);
	}
	else
	{
		if ((*stack)->index == 3)
		{
			if (((*stack)->next)->index == 2)
				return (rotate(stack, "ra\n"), swap(stack, "sa\n"), *stack);
			return (rotate(stack, "ra\n"), *stack);
		}
		if (((*stack)->next)->index == 1)
			return (swap(stack, "sa\n"), *stack);
		return (reverse_rotate(stack, "rra\n"), *stack);
	}
}
