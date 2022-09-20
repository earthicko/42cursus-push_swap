NAME			= push_swap
BONUS			= checker
LIBFT_DIR		= libft
LIBFT			= libft.a
LINK_LIBFT		= -L $(LIBFT_DIR) $(LIBFT_DIR)/$(LIBFT)
INC_DIR_LIBFT	= -I $(LIBFT_DIR)
INC_DIR_DEBUG	= -I includes_debug
INC_DIR			= -I . $(INC_DIR_LIBFT) -I includes $(INC_DIR_DEBUG)

SRCNAME_DEBUG	= \
				./debug/deque_debug \
				./debug/node_debug \
				./debug/state_debug

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
				./sorter/optimisation/sort_optimised_b_3x_utils

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
				./sorter/sort_stack_utils 

SRC				= $(addsuffix .c, $(SRCNAME))
OBJ				= $(addsuffix .o, $(SRCNAME))
SRC_BONUS		= $(addsuffix .c, $(SRCNAME_BONUS)))
OBJ_BONUS		= $(addsuffix .o, $(SRCNAME_BONUS))
OBJ_DEBUG		= $(addsuffix .o, $(SRCNAME_DEBUG))

RM				= rm -f
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ) $(OBJ_DEBUG) $(NAME).o
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(OBJ_DEBUG) $(NAME).o $(LINK_LIBFT) -o $(NAME)

bonus : $(LIBFT) $(OBJ_BONUS) $(BONUS).o
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ_BONUS) $(BONUS).o $(LINK_LIBFT) -o $(BONUS)

$(LIBFT) :
	make all -j 4 -C $(LIBFT_DIR)/

test_deque : $(LIBFT) $(OBJ) $(OBJ_DEBUG) debug/test_deque_main.o
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(OBJ_DEBUG) debug/test_deque_main.o $(LINK_LIBFT) -o test_deque
	./test_deque

test_array : $(LIBFT) $(OBJ) $(OBJ_DEBUG) debug/test_array_main.o
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(OBJ_DEBUG) debug/test_array_main.o $(LINK_LIBFT) -o test_array
	./test_array

test_parser : $(LIBFT) $(OBJ) $(OBJ_DEBUG) debug/test_parser_main.o
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(OBJ_DEBUG) debug/test_parser_main.o $(LINK_LIBFT) -o test_parser
	./test_parser

%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean_test :
	$(RM) debug/test_deque_main.o debug/test_array_main.o debug/test_parser_main.o

clean : clean_test
	$(RM) $(OBJ) $(OBJ_DEBUG) $(OBJ_BONUS) $(NAME).o $(BONUS).o
	make clean -C $(LIBFT_DIR)

fclean_test :
	$(RM) test_deque test_array test_parser

fclean : clean fclean_test
	$(RM) $(NAME) $(BONUS)
	make fclean -C $(LIBFT_DIR)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
