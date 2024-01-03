/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:04:07 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/03 12:07:47 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_add_front(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;

	printf("he entrado aquí:)\n");
	tmp = node;
	tmp->next = *stack;
	*stack = tmp;
}

void	del_node(t_stack **stack)
{
	t_stack	*actual;

	printf("también he entrado aquí:)\n");
	if (!stack)
	{
		printf("no existe el stack\n");
		return ;
	}
	actual = (*stack)->next;
	free(*stack);
	*stack = actual;
	actual = 0;
}

t_stack	*stack_last(t_stack *lst)
{
	t_stack	*actual;

	if (!lst)
		return (0);
	actual = lst;
	while (actual->next)
		actual = actual->next;
	return (actual);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*actual;

	if (!(*stack))
		*stack = new;
	else
	{
		actual = stack_last(*stack);
		actual->next = new;
	}
}

//stack_a = create_node(3), stack_b = create_node(5)
void	checker(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*a_linked;
	t_stack	*b_linked;

	a_linked = stack_a;
	b_linked = stack_b;
	stack_add_back(&stack_a, create_node(2));
	stack_add_back(&stack_a, create_node(1));
	stack_add_back(&stack_b, create_node(4));
	stack_add_back(&stack_b, create_node(6));
	del_node(&stack_a->next);
	stack_add_front(&a_linked, create_node(2));
	while (a_linked->next)
	{
	//	printf("nodo a %i\n", a_linked->value);
		printf("pos nodo a %i\n", a_linked->pos);
		a_linked = a_linked->next;
	}
	//printf("nodo a %i\n", a_linked->value);
	printf("pos nodo a %i\n", a_linked->pos);
	while (b_linked->next)
	{
	//	printf("nodo b %i\n", b_linked->value);
		printf("pos nodo b %i\n", b_linked->pos);
		b_linked = b_linked->next;
	}
	//printf("nodo b %i\n", b_linked->value);
	printf("pos nodo b %i\n", b_linked->pos);
}
