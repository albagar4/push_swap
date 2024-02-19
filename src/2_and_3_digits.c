/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_and_3_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:36:48 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/15 13:36:54 by albagar4         ###   ########.fr       */
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

void	smart_rotate(t_stack **stack_a, int index)
{
	t_stack	*start;
	int		pos;
	int		size;

	size = ft_len_list(stack_a);
	start = *stack_a;
	pos = 0;
	while ((*stack_a)->index != index)
		*stack_a = (*stack_a)->next;
	pos = (*stack_a)->pos;
	*stack_a = start;
	if (pos <= size / 2)
		while ((*stack_a)->index != index)
			rotate(stack_a, "ra\n");
	else
		while ((*stack_a)->index != index)
			reverse_rotate(stack_a, "rra\n");
}

t_stack	*five_digits_sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while ((*stack_a)->index != 1)
		smart_rotate(stack_a, 1);
	push(&stack_b, stack_a, "pb\n");
	while ((*stack_a)->index != 2)
		smart_rotate(stack_a, 2);
	push(&stack_b, stack_a, "pb\n");
	*stack_a = three_digits_sort(stack_a);
	push(stack_a, &stack_b, "pa\n");
	push(stack_a, &stack_b, "pa\n");
	return (*stack_a);
}
