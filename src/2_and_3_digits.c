/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_and_3_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:04:56 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/18 16:03:44 by albagar4         ###   ########.fr       */
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
	int	first;
	int	second;
	int	third;

	first = ((*stack)->index);
	second = (((*stack)->next)->index);
	third = (((*stack)->next->next)->index);
	if ((*stack)->index == minimum(first, second, third))
	{
		if (((*stack)->next->next)->index > ((*stack)->next)->index)
			return (*stack);
		return (reverse_rotate(stack, "rra\n"), swap(stack, "sa\n"), *stack);
	}
	else
	{
		if ((*stack)->index == maximum(first, second, third))
		{
			if (((*stack)->next)->index == middle(first, second, third))
				return (rotate(stack, "ra\n"), swap(stack, "sa\n"), *stack);
			return (rotate(stack, "ra\n"), *stack);
		}
		if (((*stack)->next)->index == minimum(first, second, third))
			return (swap(stack, "sa\n"), *stack);
		return (reverse_rotate(stack, "rra\n"), *stack);
	}
}
