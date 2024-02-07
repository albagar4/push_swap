/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:18:47 by albagar4          #+#    #+#             */
/*   Updated: 2024/02/07 19:36:00 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

int		count_numbers(char *str);
long	*one_argument(char *string, int *size);
long	*multiple_arguments(char **str, int *size);
int		nbr_checker(long *nbr_array, int size);
t_stack	*init_stack(void);

t_stack	*create_node(long nbr);
t_stack	*arr_to_list(long *stack, int size);

void	push(t_stack **stack_a, t_stack **stack_b, char *msg);
void	swap(t_stack **stack_a, char *msg);
void	rotate(t_stack **stack, char *msg);
void	reverse_rotate(t_stack **stack, char *msg);
void	swap_swap(t_stack **stack_a, t_stack **stack_b);
void	rotate_rotate(t_stack **stack_1, t_stack **stack_2);
void	reverse_rotate_rotate(t_stack **stack_1, t_stack **stack_2);

int		cal_abs(int nbr);
int		ft_len_list(t_stack **stack);
void	print_cost_a(t_stack **stack, char *name);
void	print_cost_b(t_stack **stack, char *name);
void	print_target_pos(t_stack **stack, char *name);
void	print_stack(t_stack **stack, char *name);
void	print_index(t_stack **stack, char *name);
void	print_pos(t_stack **stack, char *name);
void	print_node(t_stack *stack, char *name);

void	del_node(t_stack **stack);
void	stack_add_front(t_stack **stack, t_stack *node);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_prelast(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*copy_node(t_stack *node);
void	checker(t_stack *stack_a, t_stack *stack_b);
t_stack	*pop_first(t_stack **stack);

void	index_assign(t_stack **stack_a, int size);
void	position_control(t_stack **stack);
int		minimum(int a, int b, int c);
int		middle(int a, int b, int c);
int		maximum(int a, int b, int c);

t_stack	*two_digits_sort(t_stack **stack);
t_stack	*three_digits_sort(t_stack **stack);
t_stack	*first_push(t_stack **stack_a, t_stack **stack_b, int size);
int		movement_seq(t_stack **stb, int pos);
void	seq_nbr_1(t_stack **sta, t_stack **stb, int tgt_pos);
void	seq_nbr_2(t_stack **sta, t_stack **stb, int tgt_pos);
void	seq_nbr_3(t_stack **sta, t_stack **stb, int tgt_pos);

int		compute_target_pos(t_stack *sta, t_stack *stb);
void	determine_target_pos(t_stack **sta, t_stack **stb);
void	get_cost_b(t_stack **stb);
void	get_cost_a(t_stack **sta, t_stack **stb);
int		det_init_total_cost(t_stack *stb);
int		giving_pos(t_stack *stb, int total_cost);
int		get_cheapest_cost(t_stack **stb);

int		keep_cost_a(t_stack **stb, int tgt_pos);
int		keep_cost_b(t_stack **stb, int tgt_pos);

void	final_movements(t_stack **stack_a, int size);
t_stack	*more_than_three(t_stack *stack_a, int size);
#endif