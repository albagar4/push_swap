/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:37:23 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/15 13:37:26 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Now we have a long array, and we have to convert it into a link list, in which
//each node is each number.
//It's necessary to create some modified bonus of libft
t_stack	*create_node(long nbr)
{
	static int	pos = 0;
	t_stack		*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = nbr;
	node->index = -1;
	node->pos = pos;
	node->target_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	pos++;
	return (node);
}

t_stack	*next_node(t_stack **node, t_stack *new)
{
	t_stack	*tmp;

	if (!(*node))
		*node = new;
	else
	{
		tmp = *node;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

//The main function. During the while loop creates a new node and allocates it
//linked to the last node created
t_stack	*arr_to_list(long *stack, int size)
{
	t_stack	*list;
	t_stack	*tmp;
	int		i;

	i = 0;
	list = create_node(stack[i]);
	i++;
	tmp = list;
	while (i < size)
	{
		tmp = next_node(&list, create_node(stack[i]));
		i++;
	}
	(void)list;
	(void)tmp;
	return (free(stack), list);
}
