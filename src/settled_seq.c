/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settled_seq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:22:36 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/05 20:41:04 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	final_movements(t_stack **stack_a, int size)
{
	int		pos;
	int		count;
	t_stack	*start;

	count = 0;
	start = *stack_a;
	while ((*stack_a)->index != 1)
		*stack_a = (*stack_a)->next;
	pos = (*stack_a)->pos;
	*stack_a = start;
	if (pos <= size / 2)
		while (count++ <= pos)
			rotate(stack_a, "ra\n");
	else
		while (count++ <= (size - pos))
			reverse_rotate(stack_a, "rra\n");
}

void	more_than_three(t_stack **stack_a, int size)
{
	t_stack	*stack_b;
	int		cheapest;

	index_assign(stack_a, size);
	stack_b = first_push(stack_a, &stack_b, size);
	print_stack(&stack_b, "stack_b después del primer pb general");
	print_stack(stack_a, "stack_a después del primer pb general");
	while (stack_b)
	{
		position_control(&stack_b);
		determine_target_pos(stack_a, &stack_b);
		get_cost_b(&stack_b);
		get_cost_a(stack_a, &stack_b);
		cheapest = get_cheapest_cost(&stack_b);
		size = movement_seq(&stack_b, cheapest);
		if (size == 1)
			seq_nbr_1(stack_a, &stack_b, cheapest);
		else if (size == 2)
			seq_nbr_2(stack_a, &stack_b, cheapest);
		else if (size == 3)
			seq_nbr_3(stack_a, &stack_b, cheapest);
		print_stack(stack_a, "stack_a");
		print_stack(&stack_b, "stack_b");
	}
	// final_movements(stack_a, size);
	print_stack(stack_a, "stack_a");
}
