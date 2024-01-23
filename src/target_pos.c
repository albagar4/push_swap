/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:12:03 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/23 18:02:38 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	det_diff(t_stack *stack_a, t_stack *stack_b)
{
	int	diff;

	while (stack_a)
	{
		if (stack_a->index > stack_b->index)
			diff = stack_a->pos;
		stack_a = stack_a->next;
	}
	return (diff);
}

void	determine_target_pos(t_stack **sta, t_stack **stb)
{
	int		diff;
	t_stack	*start;

	diff = det_diff(*sta, *stb);
	start = *sta;
	while (*stb)
	{
		*sta = start;
		while (*sta)
		{
			if ((*sta)->index < diff && (*sta)->index < (*stb)->index)
				diff = (*sta)->pos;
			*sta = (*sta)->next;
		}
		(*stb)->target_pos = diff;
		printf("target->pos en %i valor es %i\n", (*stb)->value, (*stb)->target_pos);
		*stb = (*stb)->next;
	}
	return ;
}
