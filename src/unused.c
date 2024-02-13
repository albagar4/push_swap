/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:00:24 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/13 16:00:29 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// t_stack	*init_stack(void)
// {
// 	t_stack	*ret;

// 	ret = create_node(0);
// 	del_node(&ret);
// 	return (ret);
// }

// void	print_cost_a(t_stack **stack, char *name)
// {
// 	t_stack	*tmp;

// 	tmp = *stack;
// 	printf("%s:\n", name);
// 	while (tmp)
// 	{
// 		printf("\t%i\n", tmp->cost_a);
// 		tmp = (tmp->next);
// 	}
// }

// void	print_cost_b(t_stack **stack, char *name)
// {
// 	t_stack	*tmp;

// 	tmp = *stack;
// 	printf("%s:\n", name);
// 	while (tmp)
// 	{
// 		printf("\t%i\n", tmp->cost_b);
// 		tmp = (tmp->next);
// 	}
// }

// void	print_target_pos(t_stack **stack, char *name)
// {
// 	t_stack	*tmp;

// 	tmp = *stack;
// 	printf("%s:\n", name);
// 	while (tmp)
// 	{
// 		printf("\t%i\n", tmp->target_pos);
// 		tmp = (tmp->next);
// 	}
// }

void	print_stack(t_stack **stack, char *name)
{
	t_stack	*tmp;

	tmp = *stack;
	printf("%s:\n", name);
	while (tmp)
	{
		printf("\t%i\n", tmp->value);
		tmp = (tmp->next);
	}
}

// void	print_index(t_stack **stack, char *name)
// {
// 	t_stack	*tmp;

// 	tmp = *stack;
// 	printf("%s:\n", name);
// 	while (tmp)
// 	{
// 		printf("\t%i\n", tmp->index);
// 		tmp = (tmp->next);
// 	}
// }

// void	print_pos(t_stack **stack, char *name)
// {
// 	t_stack	*tmp;

// 	tmp = *stack;
// 	printf("%s:\n", name);
// 	while (tmp)
// 	{
// 		printf("\t%i\n", tmp->pos);
// 		tmp = (tmp->next);
// 	}
// }

// void	print_node(t_stack *stack, char *name)
// {
// 	printf("%s->value = %i\n", name, stack->value);
// 	printf("%s->index = %i\n", name, stack->index);
// 	printf("%s->pos = %i\n", name, stack->pos);
// 	printf("%s->target_pos = %i\n", name, stack->target_pos);
// 	printf("%s->cost_a = %i\n", name, stack->cost_a);
// 	printf("%s->cost_b = %i\n", name, stack->cost_b);
// 	printf("%s->next = %p\n", name, stack->next);
// }
