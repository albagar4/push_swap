NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF_DIR = include/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_DIR = $(FT_PRINTF_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
CHECKER_DIR = src/checker
INCLUDES = -I . -I include -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR)

COMMON_SRCS = src/argument_parse.c src/convert_to_list.c src/movements_1.c src/utils.c src/modified_functions.c src/movements_2.c src/assigning_index.c src/2_and_3_digits.c src/auxiliar_index_ft.c src/more_than_3.c src/more_than_3_utils.c src/target_pos.c src/ft_costs.c src/keep_data.c src/settled_seq.c
CHECKER_SRCS = $(COMMON_SRCS) $(CHECKER_DIR)/checker.c $(CHECKER_DIR)/get_next_line/get_next_line.c $(CHECKER_DIR)/get_next_line/get_next_line_utils.c
PUSH_SWAP_SRCS = $(COMMON_SRCS) src/main.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(PUSH_SWAP_OBJS) $(LIBFT) $(FT_PRINTF) -o push_swap

checker: $(CHECKER_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(CHECKER_OBJS) $(LIBFT) $(FT_PRINTF) -o checker

bonus: $(NAME) checker

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) checker
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
