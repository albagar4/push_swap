/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:12:39 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/24 16:16:01 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_cost_b(t_stack **stb)
{
	int		size;
	t_stack	*start;

	position_control(stb);
	size = ft_len_list(stb);
	start = *stb;
	if (*stb == NULL)
		return ;
	while (*stb)
	{
		if ((*stb)->pos <= (size / 2))
			(*stb)->cost_b = (*stb)->pos;
		else
			(*stb)->cost_b = (size - (*stb)->pos) * (-1);
		*stb = (*stb)->next;
	}
	*stb = start;
}

void	get_cost_a(t_stack **sta, t_stack **stb)
{
	int		size;
	t_stack	*start_sta;
	t_stack	*start_stb;

	size = ft_len_list(sta);
	start_sta = *sta;
	start_stb = *stb;
	while (*stb)
	{
		while (*sta)
		{
			if ((*stb)->target_pos == (*sta)->pos)
			{
				if ((*sta)->pos <= (size / 2))
					(*stb)->cost_a = (*sta)->pos;
				else
					(*stb)->cost_a = (size - (*sta)->pos) * (-1);
			}
			*sta = (*sta)->next;
		}
		*sta = start_sta;
		*stb = (*stb)->next;
	}
	*stb = start_stb;
}
