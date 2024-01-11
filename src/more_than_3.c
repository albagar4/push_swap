/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:08:06 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/11 13:09:32 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*first_push(t_stack **stack_a, int size)
{
	int		i;
	t_stack	*stack_b;
	t_stack	*start;

	i = 0;
	stack_b = create_node(0);
	start = *stack_a;
	while (*stack_a && )
	{
		while (i <= (size - 3))
		{
			if (((*stack_a)->index < (size / 2)) && (i < (size / 2)))
				push(stack_b, *stack_a, "pb\n");
			else if (i >= (size / 2))
				push(stack_b, *stack_a, "pb\n");
			else
				*stack_a = (*stack_a)->next;
			i++;
		}
	}
	*stack_a = start;
	*stack_a = index_keeper(&stack_a);
	three_digits_sort(&stack_a);
	*stack_a = index_keeper(&stack_a);
	return (stack_b);
}
