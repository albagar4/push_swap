/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:12:03 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/05 19:54:01 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	compute_target_pos(t_stack *sta, t_stack *stb)
{
	int	res;
	int	diff;

	diff = INT32_MAX;
	res = 0;
	while (sta)
	{
		if (((sta->index) > (stb->index))
			&& ((sta->index) - (stb->index)) < diff)
		{
			diff = sta->index - stb->index;
			res = sta->pos;
		}
		sta = sta->next;
	}
	return (res);
}

void	determine_target_pos(t_stack **sta, t_stack **stb)
{
	t_stack	*start_b;

	position_control(sta);
	start_b = *stb;
	while (*stb)
	{
		(*stb)->target_pos = compute_target_pos(*sta, *stb);
		*stb = (*stb)->next;
	}
	*stb = start_b;
}
