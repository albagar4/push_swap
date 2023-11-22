/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:46:21 by albagar4          #+#    #+#             */
/*   Updated: 2023/11/22 16:53:19 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Lo primero que voy a hacer es crear (o sacar de libft) una función que me 
//convierta los argumentos pasados en pantalla en enteros, y ellos mismos 
//almacenarlos en un array
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

int	*one_argument(char *string, int *size)
{
	char	**each_nbr;
	int		*stack;
	int		i_str;
	int		i_int;

	if (count_numbers(string) == -1)
	{
		printf("Hay algún valor incorrecto en los argumentos\n");
		return (NULL);
	}
	*size = count_numbers(string);
	stack = (int *)malloc(count_numbers(string) * sizeof(int));
	if (!stack)
		return (NULL);
	i_str = 0;
	i_int = 0;
	each_nbr = ft_split(string, ' ');
	while (each_nbr[i_str] != NULL)
	{
		stack[i_int++] = ft_atoi((const char *)each_nbr[i_str++]);
		printf("%i\n", stack[i_int - 1]);
	}
	return (stack);
}

int	*multiple_arguments(char **str, int *size)
{
	int	i1;
	int	i2;
	int	*stack;

	i1 = 1;
	while (str[i1] != NULL)
		i1++;
	*size = i1 - 1;
	stack = (int *)malloc(i1 * sizeof(int));
	if (!stack)
		return (printf("mala reserva de memoria\n"), NULL);
	i1 = 1;
	i2 = 0;
	while (str[i1] != NULL)
	{
		printf("str[i1] == %s\n", str[i1]);
		if (ft_strncmp(str[i1], "0", 1) != 0 && (ft_atoi(str[i1]) == 0))
			return (printf("Argumento no válido\n"), NULL);
		stack[i2++] = ft_atoi((const char *)str[i1++]);
		printf("he introducido un valor, %i\n", stack[i2 - 1]);
	}
	return (stack);
}

//Dos funciones que checkeen los números, que no haya dobles y que tampoco
//haya valores no permitidos por int
int	nbr_checker(int *nbr_array, int size)
{
	int	i;
	int	parse;

	i = 0;
	parse = 1;
	while (i <= size)
	{
		while (parse <= size)
		{
			if (nbr_array[i] == nbr_array[parse])
				return (-1);
			parse++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char	*argv[])
{
	int	*stack_a;
	int	size;

	size = 0;
	if (argc < 2)
	{
		printf("Introduce argumentos\n");
		return (-1);
	}
	if (argc == 2)
		stack_a = one_argument(argv[1], &size);
	if (argc > 2)
		stack_a = multiple_arguments(argv, &size);
	if (nbr_checker(stack_a, size) == -1)
		return (printf("hay números duplicados\n"), 0);
	return (0);
}
