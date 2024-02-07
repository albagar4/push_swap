/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:46:21 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/07 20:02:28 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//This file converts the argument or multiple arguments into a long array
//Depending on the number of arguments the main calls one function or other
int	count_numbers(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || (str[i] == '-'
				&& str[i + 1] >= '0' && str[i + 1] <= '9'))
		{
			if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
			{
				i++;
				count++;
			}
			else
				i++;
		}
		else
			return (-1);
	}
	return (count);
}

long	*one_argument(char *string, int *size)
{
	char	**each_nbr;
	long	*stack;
	int		i_str;
	int		i_int;

	if (count_numbers(string) == -1)
	{
		printf("Hay algún valor incorrecto en los argumentos\n");
		return (NULL);
	}
	*size = count_numbers(string);
	stack = (long *)malloc(count_numbers(string) * sizeof(long));
	if (!stack)
		return (NULL);
	i_str = 0;
	i_int = 0;
	each_nbr = ft_split(string, ' ');
	while (each_nbr[i_str] != NULL)
		stack[i_int++] = ft_atol((const char *)each_nbr[i_str++]);
	return (stack);
}

long	*multiple_arguments(char **str, int *size)
{
	int		i1;
	int		i2;
	long	*stack;

	i1 = 1;
	while (str[i1] != NULL)
		i1++;
	*size = i1 - 1;
	stack = (long *)malloc(i1 * sizeof(long));
	if (!stack)
		return (printf("mala reserva de memoria\n"), NULL);
	i1 = 1;
	i2 = 0;
	while (str[i1] != NULL)
	{
		if (ft_strncmp(str[i1], "0", 1) != 0 && (ft_atol(str[i1]) == 0))
			return (printf("Argumento no válido\n"), NULL);
		stack[i2++] = ft_atol((const char *)str[i1++]);
	}
	return (stack);
}

//A function that checks if there are double numbers or non valid values
int	nbr_checker(long *nbr_array, int size)
{
	int	i;
	int	parse;

	i = 0;
	while (i <= size)
	{
		parse = i + 1;
		while (parse <= size)
		{
			if (nbr_array[i] == nbr_array[parse])
				return (printf("números duplicados %li\n", nbr_array[i]), -1);
			parse++;
		}
		i++;
	}
	i = 0;
	while (i <= size)
	{
		if (nbr_array[i] < INT32_MIN || nbr_array[i] > INT32_MAX)
			return (printf("valor no aceptado %li\n", nbr_array[i]), -1);
		i++;
	}
	return (0);
}

t_stack	*init_stack(void)
{
	t_stack	*ret;

	ret = create_node(0);
	del_node(&ret);
	return (ret);
}

int	main(int argc, char *argv[])
{
	long	*arr;
	int		size;
	t_stack	*stack_a;

	size = 0;
	if (argc < 2)
		return (printf("Introduce argumentos\n"), -1);
	if (argc == 2)
		arr = one_argument(argv[1], &size);
	if (argc > 2)
		arr = multiple_arguments(argv, &size);
	if (nbr_checker(arr, size) == -1)
		return (printf("Error\n"), 0);
	stack_a = arr_to_list(arr, size);
	index_assign(&stack_a, size);
	// print_stack(&stack_a, "antes del ordenamiento");
	if (size == 2)
		stack_a = two_digits_sort(&stack_a);
	else if (size == 3)
		stack_a = three_digits_sort(&stack_a);
	else if (size > 3)
		stack_a = more_than_three(stack_a, size);
	// print_stack(&stack_a, "despues del ordenamiento");
	return (0);
}

// int	main(void)
// {
// 	t_stack	*sta;
// 	t_stack	*stb;
// 	// int		tgt_pos;
// 	int		cheapest;
// 	int		seq;

// 	sta = create_node(4);
// 	stb = create_node(3);
// 	stack_add_front(&sta, create_node(2));
// 	stack_add_front(&sta, create_node(7));
// 	stack_add_front(&stb, create_node(6));
// 	stack_add_front(&stb, create_node(5));
// 	stack_add_front(&stb, create_node(1));
// 	position_control(&stb);
// 	position_control(&sta);
// 	t_stack *tmp_a = sta;
// 	t_stack *tmp_b = stb;
// 	while (sta) {
// 		sta->index = sta->value;
// 		sta = sta->next;
// 	}
// 	while (stb) {
// 		stb->index = stb->value;
// 		stb = stb->next;
// 	}
// 	sta=tmp_a;
// 	stb=tmp_b;
// 	print_stack(&sta, "stack_a");
// 	print_stack(&stb, "stack_b");
// 	while (stb)
// 	{
// 		position_control(&stb);
// 		determine_target_pos(&sta, &stb);
// 		print_target_pos(&stb, "target_pos en stb");
// 		get_cost_b(&stb);
// 		get_cost_a(&sta, &stb);
// 		print_cost_b(&stb, "cost_b en stb");
// 		print_cost_a(&stb, "cost_a en stb");
// 		cheapest = get_cheapest_cost(&stb);
// 		printf("%i es la posicion del cheapest cost\n", cheapest);
// 		seq = movement_seq(&stb, cheapest);
// 		printf("%i es seq\n", seq);
// 		if (seq == 1)
// 			seq_nbr_1(&sta, &stb, cheapest);
// 		else if (seq == 2)
// 			seq_nbr_2(&sta, &stb, cheapest);
// 		else if (seq == 3)
// 			seq_nbr_3(&sta, &stb, cheapest);
// 		// reset_target_pos(&stb);
// 		print_stack(&sta, "stack_a");
// 		print_stack(&stb, "stack_b");
// 	}
// 	// printf("la seq es %i\n", seq);
// 	return (0);
// }
