/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:37:51 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/15 13:47:10 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_stack **stack_a, int size)
{
	index_assign(stack_a, size);
	if (size == 2)
		*stack_a = two_digits_sort(stack_a);
	else if (size == 3)
		*stack_a = three_digits_sort(stack_a);
	else if (size == 5 && is_sorted(*stack_a) == 1)
		*stack_a = five_digits_sort(stack_a);
	else if (size > 3 && is_sorted(*stack_a) == 1)
		*stack_a = more_than_three(*stack_a, size);
}

int	main(int argc, char *argv[])
{
	long	*arr;
	int		size;
	t_stack	*stack_a;

	size = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
		arr = one_argument(argv[1], &size);
	if (argc > 2)
		arr = multiple_arguments(argv, &size);
	if (arr == NULL || argv[1][0] == '\0' || nbr_checker(arr, size) == -1)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), 0);
	stack_a = arr_to_list(arr, size);
	push_swap(&stack_a, size);
	free_stack(&stack_a);
	return (0);
}
