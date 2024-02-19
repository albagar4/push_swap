/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:44:41 by lgaudin           #+#    #+#             */
/*   Updated: 2024/02/14 16:22:24 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	parse_instruction(char *instruction, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(instruction, "rr\n", 4))
		rotate_rotate(stack_a, stack_b, "");
	else if (!ft_strncmp(instruction, "ra\n", 4))
		rotate(stack_a, "");
	else if (!ft_strncmp(instruction, "rb\n", 4))
		rotate(stack_b, "");
	else if (!ft_strncmp(instruction, "rrr\n", 5))
		reverse_rotate_rotate(stack_a, stack_b, "");
	else if (!ft_strncmp(instruction, "rra\n", 5))
		reverse_rotate(stack_a, "");
	else if (!ft_strncmp(instruction, "rrb\n", 5))
		reverse_rotate(stack_b, "");
	else if (!ft_strncmp(instruction, "pa\n", 4))
		push(stack_a, stack_b, "");
	else if (!ft_strncmp(instruction, "pb\n", 4))
		push(stack_b, stack_a, "");
	else if (!ft_strncmp(instruction, "sa\n", 4))
		swap(stack_a, "");
	else if (!ft_strncmp(instruction, "sb\n", 4))
		swap(stack_b, "");
	else if (!ft_strncmp(instruction, "ss\n", 4))
		swap_swap(stack_a, stack_b, "");
	else
		return (0);
	return (1);
}

int	get_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		if (!parse_instruction(instruction, stack_a, stack_b))
			return (free(instruction), 0);
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
	return (1);
}

int	check_args(int argc, char *argv[], long **arr, int *size)
{
	if (argc == 2)
		*arr = one_argument(argv[1], size);
	if (argc > 2)
		*arr = multiple_arguments(argv, size);
	if (*arr == NULL || argv[1][0] == '\0' || nbr_checker(*arr, *size) == -1)
	{
		free(*arr);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	long	*arr;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	size = 0;
	arr = NULL;
	if (check_args(argc, argv, &arr, &size))
		return (0);
	stack_a = arr_to_list(arr, size);
	stack_b = NULL;
	if (!get_instructions(&stack_a, &stack_b))
		return (ft_putstr_fd("Error\n", STDERR_FILENO),
			free_stack(&stack_a), free_stack(&stack_b), 0);
	if (!is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
