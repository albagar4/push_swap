/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:38:28 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/15 13:38:30 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*first_push(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (count < size)
	{
		if (((*stack_a)->index < (size / 2)) && (i < (size / 2)))
		{
			push(stack_b, stack_a, "pb\n");
			i++;
		}
		else
			rotate(stack_a, "ra\n");
		count++;
	}
	while (ft_len_list(stack_a) > 3)
	{
		if ((*stack_a)->index < (size - 2))
			push(stack_b, stack_a, "pb\n");
		else
			rotate(stack_a, "ra\n");
	}
	*stack_a = three_digits_sort(stack_a);
	return (*stack_b);
}

int	movement_seq(t_stack **stb, int pos)
{
	t_stack	*start_b;

	start_b = *stb;
	while ((*stb)->pos != pos)
		*stb = (*stb)->next;
	if (((*stb)->cost_b > 0 && (*stb)->cost_a < 0)
		|| ((*stb)->cost_b < 0 && (*stb)->cost_a > 0))
	{
		*stb = start_b;
		return (3);
	}
	else
	{
		if ((*stb)->cost_b >= 0 && (*stb)->cost_a >= 0)
		{
			*stb = start_b;
			return (1);
		}
		else
		{
			*stb = start_b;
			return (2);
		}
	}
}

void	seq_nbr_1(t_stack **sta, t_stack **stb, int tgt_pos)
{
	int	cost_a;
	int	cost_b;

	cost_a = keep_cost_a(stb, tgt_pos);
	cost_b = keep_cost_b(stb, tgt_pos);
	while (cost_a != 0 || cost_b != 0)
	{
		if (cost_b >= cost_a)
		{
			rotate(stb, "rb\n");
			cost_b--;
		}
		else
		{
			rotate(sta, "ra\n");
			cost_a--;
		}
	}
	while (cost_a < 0)
	{
		rotate_rotate(sta, stb, "rr\n");
		cost_a++;
		cost_b++;
	}
	push(sta, stb, "pa\n");
}

void	seq_nbr_2(t_stack **sta, t_stack **stb, int tgt_pos)
{
	int	cost_a;
	int	cost_b;

	cost_a = keep_cost_a(stb, tgt_pos);
	cost_b = keep_cost_b(stb, tgt_pos);
	while (cost_b != cost_a)
	{
		if (cost_b < cost_a)
		{
			reverse_rotate(stb, "rrb\n");
			cost_b++;
		}
		else
		{
			reverse_rotate(sta, "rra\n");
			cost_a++;
		}
	}
	while (cost_a < 0)
	{
		reverse_rotate_rotate(sta, stb, "rrr\n");
		cost_a++;
		cost_b++;
	}
	push(sta, stb, "pa\n");
}

void	seq_nbr_3(t_stack **sta, t_stack **stb, int tgt_pos)
{
	int		cost_a;
	int		cost_b;

	cost_a = keep_cost_a(stb, tgt_pos);
	cost_b = keep_cost_b(stb, tgt_pos);
	while (cost_b > 0 || cost_a < 0)
		seq_3_1st_while(sta, stb, &cost_a, &cost_b);
	while (cost_b < 0 || cost_a > 0)
	{
		if (cost_a > 0)
			rotate(sta, "ra\n");
		if (cost_b < 0)
			reverse_rotate(stb, "rrb\n");
		cost_b++;
		cost_a--;
	}
	push(sta, stb, "pa\n");
}
