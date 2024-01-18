/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_index_ft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:03:40 by albagar4          #+#    #+#             */
/*   Updated: 2024/01/18 16:04:00 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	minimum(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < a && b < c)
		return (b);
	else
		return (c);
}

int	middle(int a, int b, int c)
{
	if ((a < b && a > c) || (a > b && a < c))
		return (a);
	else if ((b < a && b > c) || (b > a && b < c))
		return (b);
	else
		return (c);
}

int	maximum(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	else if (b > a && b > c)
		return (b);
	else
		return (c);
}
