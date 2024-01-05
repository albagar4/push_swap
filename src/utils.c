/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:50:55 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/05 15:13:34 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void 	print_stack(t_stack *stack, char *name)
{
	t_stack	tmp;

	tmp = *stack;
	printf("%s:\n", name);
	while (tmp.next)
	{
		printf("\t%i\n", tmp.value);
		tmp = *(tmp.next);
	}
	printf("\t%i\n\n", tmp.value);
}

void	print_node(t_stack *stack, char *name)
{
	printf("%s->value = %i\n", name, stack->value);
	printf("%s->index = %i\n", name, stack->index);
	printf("%s->pos = %i\n", name, stack->pos);
	printf("%s->target_pos = %i\n", name, stack->target_pos);
	printf("%s->cost_a = %i\n", name, stack->cost_a);
	printf("%s->cost_b = %i\n", name, stack->cost_b);
	printf("%s->next = %p\n", name, stack->next);
}