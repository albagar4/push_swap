/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:22:56 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/09 16:45:11 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **stack, char *msg)
{
	t_stack	*first_pos;

	first_pos = pop_first(stack);
	stack_add_back(stack, first_pos);
	printf("%s", msg);
}

void	rotate_rotate(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = pop_first(stack_1);
	node2 = pop_first(stack_2);
	stack_add_back(stack_1, node1);
	stack_add_back(stack_2, node2);
	printf("rr\n");
}

void	reverse_rotate(t_stack **stack, char *msg)
{
	t_stack	*last;
	t_stack	*prelast;

	last = stack_last(*stack);
	prelast = stack_prelast(*stack);
	stack_add_front(stack, last);
	prelast->next = NULL;
	printf("%s", msg);
}

void	reverse_rotate_rotate(t_stack **stack_1, t_stack **stack_2)
{
	reverse_rotate(stack_1, "");
	reverse_rotate(stack_2, "");
	printf("rrr\n");
}
