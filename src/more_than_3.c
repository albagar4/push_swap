/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:08:06 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/23 17:53:51 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*first_push(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (count < size)
	{
		if (((*stack_a)->index < (size / 2)) && (i < (size / 2)))
		{
			push(stack_b, stack_a, "pb\n");
			i++;
		}
		else
			rotate(stack_a, "ra\n");
		count++;
	}
	while (ft_len_list(stack_a) > 3)
	{
		if ((*stack_a)->index < (size - 2))
			push(stack_b, stack_a, "pb\n");
		else
			rotate(stack_a, "ra\n");
	}
	*stack_a = three_digits_sort(stack_a);
	return (*stack_b);
}
