/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:32:48 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/01 15:37:07 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	keep_cost_a(t_stack **stb, int tgt_pos)
{
	t_stack	*start;
	int		data;

	start = *stb;
	while ((*stb)->pos != tgt_pos)
		*stb = (*stb)->next;
	data = (*stb)->cost_a;
	*stb = start;
	return (data);
}

int	keep_cost_b(t_stack **stb, int tgt_pos)
{
	t_stack	*start;
	int		data;

	start = *stb;
	while ((*stb)->pos != tgt_pos)
		*stb = (*stb)->next;
	data = (*stb)->cost_b;
	*stb = start;
	return (data);
}
