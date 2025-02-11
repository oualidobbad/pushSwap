FLAGS = -Wall -Wextra -Werror
FT_PRINTF = libftprintf.a
NAME = push_swap
SRC = ft_create_node.c  ft_push_back_front.c  ft_push_nbr_stacks.c  min_max.c  push_a_b.c  push_swap.c  rank_stack.c  reverse_rotate.c  rotate.c  sort_less_than7.c  sort_stack.c  sort_three.c  swap_stacks.c
OBJ = $(SRC:.c=.o)
LIBFT = libft.a

all: $(NAME)
$(NAME): $(FT_PRINTF) $(LIBFT) $(OBJ)
	@cc $(FLAGS) $(OBJ) ft_printf/$(FT_PRINTF) libft/$(LIBFT) -o $(NAME)

$(FT_PRINTF): ft_printf
	@make -C ft_printf
$(LIBFT): libft
	@make -C libft

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

clean: cleanprintf cleanlibft
	@rm -rf $(OBJ)

fclean: fcleanprintf fcleanlibft clean
	@rm -rf $(NAME)

re: fclean all

cleanprintf:
	@make clean -C ft_printf
fcleanprintf:
	@make fclean -C ft_printf
cleanlibft:
	@make clean -C libft
fcleanlibft:
	@make fclean -C libft
.PHONY: all clean fclean re cleanprintf fcleanprintf
