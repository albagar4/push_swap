/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_3_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:38:14 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/15 13:38:16 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	seq_3_1st_while(t_stack **sta, t_stack **stb, int *cost_a, int *cost_b)
{
	if (*cost_b > 0)
	{
		rotate(stb, "rb\n");
		(*cost_b)--;
	}
	if (*cost_a < 0)
	{
		reverse_rotate(sta, "rra\n");
		(*cost_a)++;
	}
}
