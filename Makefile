NAME			= push_swap
BONUS			= checker
LIBFT_DIR		= libft
LIBFT			= libft.a
LINK_LIBFT		= -L $(LIBFT_DIR) $(LIBFT_DIR)/$(LIBFT)
INC_DIR_LIBFT	= -I $(LIBFT_DIR)
INC_DIR			= -I . $(INC_DIR_LIBFT) -I includes

SRCNAME			= \
				./utils/ft_sort_int_tab \
				./utils/free_strs \
				./utils/ft_isspace \
				./datatypes/stack \
				./datatypes/deque \
				./datatypes/deque_methods \
				./datatypes/array \
				./datatypes/state \
				./datatypes/state_swap_push \
				./datatypes/state_rotate \
				./datatypes/state_rev_rotate \
				./datatypes/state_print \
				./datatypes/stack_init_from_array \
				./datatypes/array_init_from_stack \
				./parser/parser \
				./parser/ft_split_space \
				./parser/ft_atoi_if_valid \
				./sorter/sort_stack_utils \
				./sorter/sort_a_to_b \
				./sorter/sort_b_to_a \
				./sorter/optimisation/sort_optimisation \
				./sorter/optimisation/sort_optimised_2x \
				./sorter/optimisation/sort_optimised_3x \
				./sorter/optimisation/sort_optimised_a_3x_utils \
				./sorter/optimisation/sort_optimised_b_3x_utils \
				./push_swap

SRCNAME_BONUS	= \
				./utils/ft_sort_int_tab \
				./utils/free_strs \
				./utils/ft_isspace \
				./datatypes/stack \
				./datatypes/deque \
				./datatypes/deque_methods \
				./datatypes/array \
				./datatypes/state \
				./datatypes/state_swap_push \
				./datatypes/state_rotate \
				./datatypes/state_rev_rotate \
				./datatypes/stack_init_from_array \
				./datatypes/array_init_from_stack \
				./get_next_line/get_next_line \
				./get_next_line/get_next_line_utils \
				./parser/parser \
				./parser/ft_split_space \
				./parser/ft_atoi_if_valid \
				./sorter/sort_stack_utils \
				./checker_bonus

SRC				= $(addsuffix .c, $(SRCNAME))
OBJ				= $(addsuffix .o, $(SRCNAME))
SRC_BONUS		= $(addsuffix .c, $(SRCNAME_BONUS)))
OBJ_BONUS		= $(addsuffix .o, $(SRCNAME_BONUS))

RM				= rm -f
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

all : $(NAME) bonus

$(NAME) : $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(LINK_LIBFT) -o $(NAME)

bonus : $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ_BONUS) $(LINK_LIBFT) -o $(BONUS)

$(LIBFT) :
	make all -j 4 -C $(LIBFT_DIR)/

%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean :
	$(RM) $(OBJ) $(OBJ_BONUS) $(NAME).o $(BONUS).o
	make clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME) $(BONUS)
	make fclean -C $(LIBFT_DIR)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
