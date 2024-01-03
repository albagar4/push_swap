/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:52:15 by albagar4          #+#    #+#             */
/*   Updated: 2023/11/30 18:38:44 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_x(t_stack **stack_dst, t_stack *stack_src)
{
	print_stack(*stack_dst);
	print_stack(stack_src);
	// printf("%i\n", (*stack_dst)->value);
	// printf("%i\n", (stack_src)->value);
	stack_add_front(stack_dst, stack_src);
	del_node(stack_src);
	print_stack(*stack_dst);
	print_stack(stack_src);
	// printf("%i\n", (*stack_dst)->value);
	// printf("%i\n", (stack_src)->value);
	return (0);
}