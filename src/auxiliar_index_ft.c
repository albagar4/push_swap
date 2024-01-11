/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_index_ft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:03:40 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/11 12:23:33 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	minimum(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < a && b < c)
		return (b);
	else
		return (c);
}

int	middle(int a, int b, int c)
{
	if ((a < b && a > c) || (a > b && a < c))
		return (a);
	else if ((b < a && b > c) || (b > a && b < c))
		return (b);
	else
		return (c);
}

int	maximum(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	else if (b > a && b > c)
		return (b);
	else
		return (c);
}

t_stack	*index_keeper(t_stack **stack)
{
	static int	first = -1;
	static int	second = -1;
	static int	third = -1;

	if (first == -1)
	{
		first = (*stack)->index;
		second = ((*stack)->next)->index;
		third = (((*stack)->next)->next)->index;
	}
	else
	{
		(*stack)->index = minimum(first, second, third);
		((*stack)->next)->index = middle(first, second, third);
		(((*stack)->next)->next)->index = maximum(first, second, third);
	}
	return (*stack);
}
