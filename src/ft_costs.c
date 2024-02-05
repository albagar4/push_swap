/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:12:39 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/05 20:17:25 by albagar4         ###   ########.fr       */
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

int	det_init_total_cost(t_stack *stb)
{
	int	total_cost;

	if (stb->cost_a < 0)
		total_cost = (stb->cost_a) * (-1);
	else
		total_cost = stb->cost_a;
	return (total_cost);
}

int	giving_pos(t_stack *stb, int total_cost)
{
	int	pos;
	int	check_cost;

	pos = 0;
	while (stb)
	{
		if ((stb->cost_b >= 0 && stb->cost_a >= 0)
			|| (stb->cost_b < 0 && stb->cost_a < 0))
		{
			if (stb->cost_b >= stb->cost_a)
				check_cost = cal_abs(stb->cost_b);
			else
				check_cost = cal_abs(stb->cost_a);
		}
		else
			check_cost = (cal_abs(stb->cost_b) + cal_abs(stb->cost_a));
		if (check_cost < total_cost)
		{
			total_cost = check_cost;
			pos = stb->pos;
		}
		stb = stb->next;
	}
	return (pos);
}

int	get_cheapest_cost(t_stack **stb)
{
	int		pos;
	int		total_cost;

	total_cost = det_init_total_cost(*stb);
	pos = giving_pos(*stb, total_cost);
	return (pos);
}
