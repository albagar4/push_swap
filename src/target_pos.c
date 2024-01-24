/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:12:03 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/24 15:05:53 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	det_diff(t_stack *sta, t_stack *stb, int position)
{
	int	diff;

	while (stb && stb->pos < position)
		stb = stb->next;
	while (1)
	{
		if ((sta->index) > (stb->index))
		{
			diff = (sta->index) - (stb->index);
			break ;
		}
		sta = sta->next;
	}
	return (diff);
}

void	determine_target_pos(t_stack **sta, t_stack **stb)
{
	int		diff;
	int		pos;
	t_stack	*start_a;
	t_stack	*start_b;

	position_control(sta);
	start_a = *sta;
	start_b = *stb;
	pos = (*sta)->pos;
	while (*stb)
	{
		diff = det_diff(*sta, *stb, (*stb)->pos);
		while (*sta)
		{
			if ((((*sta)->index) > ((*stb)->index))
				&& (((*sta)->index) - ((*stb)->index)) < diff)
			{
				diff = (*sta)->index - (*stb)->index;
				pos = (*sta)->pos;
			}
			*sta = (*sta)->next;
		}
		*sta = start_a;
		(*stb)->target_pos = pos;
		*stb = (*stb)->next;
	}
	*stb = start_b;
}
