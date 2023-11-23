/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:52:15 by albagar4          #+#    #+#             */
/*   Updated: 2023/11/23 18:47:31 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_x(t_stack **stack_dst, t_stack *stack_src)
{
	t_stack	*tmp;

	printf("stack_dst tiene de valor %i\n", stack_dst[0]->value);
	printf("stack_src tiene de valor %i\n", stack_src->value);
	tmp = stack_src->next;
	stack_src->next = *stack_dst;
	*stack_dst = stack_src;
	printf("en el top de stack A hay %i\n", stack_dst[0]->value);
	printf("tmp tiene dentro: %i\n", tmp->value);
	printf("el segundo lugar de A tiene %i\n", stack_dst[1]->value);
	return (0);
}
