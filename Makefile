# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 12:29:20 by albagar4          #+#    #+#              #
#    Updated: 2024/01/09 17:27:29 by albagar4         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# LIBFT_DIR = ft_printf/libft
LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a
# FT_PRINTF_DIR = ft_printf
# FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
INCLUDES = -I . -I include -I $(LIBFT_DIR)

COMMON_SRCS = src/argument_parse.c src/convert_to_list.c src/movements_1.c src/utils.c src/modified_functions.c src/movements_2.c src/assigning_index.c
PUSH_SWAP_SRCS = $(COMMON_SRCS)
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(PUSH_SWAP_OBJS) $(LIBFT) -o push_swap

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# $(FT_PRINTF):
# 	@$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(PUSH_SWAP_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
#	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
#	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re