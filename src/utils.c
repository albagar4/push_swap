/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:50:55 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/13 16:30:21 by albagar4         ###   ########.fr       */
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

int	is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		del_node(stack);
		*stack = tmp;
	}
	free(*stack);
}
