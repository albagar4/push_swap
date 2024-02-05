/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:50:55 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/05 20:06:45 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cal_abs(int nbr)
{
	int	abs;

	if (nbr >= 0)
		abs = nbr;
	else
		abs = (nbr * (-1));
	return (abs);
}

int	ft_len_list(t_stack **stack)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = *stack;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

void	print_cost_a(t_stack **stack, char *name)
{
	t_stack	*tmp;

	tmp = *stack;
	printf("%s:\n", name);
	while (tmp)
	{
		printf("\t%i\n", tmp->cost_a);
		tmp = (tmp->next);
	}
}

void	print_cost_b(t_stack **stack, char *name)
{
	t_stack	*tmp;

	tmp = *stack;
	printf("%s:\n", name);
	while (tmp)
	{
		printf("\t%i\n", tmp->cost_b);
		tmp = (tmp->next);
	}
}

void	print_target_pos(t_stack **stack, char *name)
{
	t_stack	*tmp;

	tmp = *stack;
	printf("%s:\n", name);
	while (tmp)
	{
		printf("\t%i\n", tmp->target_pos);
		tmp = (tmp->next);
	}
}

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

void	print_index(t_stack **stack, char *name)
{
	t_stack	*tmp;

	tmp = *stack;
	printf("%s:\n", name);
	while (tmp)
	{
		printf("\t%i\n", tmp->index);
		tmp = (tmp->next);
	}
}

void	print_pos(t_stack **stack, char *name)
{
	t_stack	*tmp;

	tmp = *stack;
	printf("%s:\n", name);
	while (tmp)
	{
		printf("\t%i\n", tmp->pos);
		tmp = (tmp->next);
	}
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

//stack_a = create_node(3), stack_b = create_node(5)
// void	checker(t_stack *stack_a, t_stack *stack_b)
// {
// 	stack_add_back(&stack_a, create_node(2));
// 	stack_add_back(&stack_a, create_node(1));
// 	stack_add_back(&stack_b, create_node(4));
// 	stack_add_back(&stack_b, create_node(6));
// 	print_stack(stack_a, "stack_a in checker()");
// 	print_stack(stack_b, "stack_b in checker()");
// }
