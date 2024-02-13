/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settled_seq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:22:36 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/13 17:18:08 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	final_movements(t_stack **stack_a, int size)
{
	int		pos;
	int		count;
	t_stack	*start;

	count = 0;
	position_control(stack_a);
	start = *stack_a;
	while ((*stack_a)->index != 1)
		*stack_a = (*stack_a)->next;
	pos = (*stack_a)->pos;
	if (pos == 0)
		return ;
	*stack_a = start;
	if (pos <= size / 2)
		while (count++ < pos)
			rotate(stack_a, "ra\n");
	else
		while (count++ < (size - pos))
			reverse_rotate(stack_a, "rra\n");
}

t_stack	*more_than_three(t_stack *stack_a, int size)
{
	t_stack	*stack_b;
	int		cheapest;
	int		seq;

	stack_b = NULL;
	stack_b = first_push(&stack_a, &stack_b, size);
	while (stack_b)
	{
		position_control(&stack_b);
		determine_target_pos(&stack_a, &stack_b);
		get_cost_b(&stack_b);
		get_cost_a(&stack_a, &stack_b);
		cheapest = get_cheapest_cost(&stack_b);
		seq = movement_seq(&stack_b, cheapest);
		if (seq == 1)
			seq_nbr_1(&stack_a, &stack_b, cheapest);
		else if (seq == 2)
			seq_nbr_2(&stack_a, &stack_b, cheapest);
		else if (seq == 3)
			seq_nbr_3(&stack_a, &stack_b, cheapest);
	}
	final_movements(&stack_a, size);
	free_stack(&stack_b);
	return (stack_a);
}
