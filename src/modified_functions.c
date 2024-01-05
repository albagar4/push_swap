/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:04:07 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/05 17:13:25 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_add_front(t_stack **stack, t_stack *node)
{
	node->next = *stack;
	*stack = node;
}

void	del_node(t_stack **stack)
{
	t_stack	*actual;

	if (!stack)
		return ;
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

t_stack	*pop_first(t_stack **stack)
{
	t_stack	*excluded;

	excluded = *stack;
	*stack = (*stack)->next;
	excluded->next = NULL;
	return (excluded);
}

//stack_a = create_node(3), stack_b = create_node(5)
void	checker(t_stack *stack_a, t_stack *stack_b)
{
	stack_add_back(&stack_a, create_node(2));
	stack_add_back(&stack_a, create_node(1));
	stack_add_back(&stack_b, create_node(4));
	stack_add_back(&stack_b, create_node(6));
	print_stack(stack_a, "stack_a in checker()");
	print_stack(stack_b, "stack_b in checker()");
	// print_stack(stack_b, "stack_b in checker()");
	// push_b(&stack_b, &stack_a);
	// print_stack(stack_a, "stack_a in checker() after one push_b");
	// print_stack(stack_b, "stack_b in checker() after one push_b");
	// push_a(&stack_a, &stack_b);
	// print_stack(stack_a, "stack_a in checker() after one push_a");
	// print_stack(stack_b, "stack_b in checker() after one push_a");
	// printf("\n\n\n");
	// swap_a(&stack_a);
	// swap_b(&stack_b);
	double_swap(&stack_a, &stack_b);
	print_stack(stack_a, "stack_a after swap_a");
	print_stack(stack_b, "stack_b after swap_a");
}
