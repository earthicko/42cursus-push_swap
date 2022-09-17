NAME			= push_swap
LIBFT_DIR		= libft
LIBFT			= libft.a
LINK_LIBFT		= -L $(LIBFT_DIR) $(LIBFT_DIR)/$(LIBFT)
INC_DIR_LIBFT	= -I $(LIBFT_DIR)
INC_DIR_DEBUG	= -I includes_debug
INC_DIR			= -I . $(INC_DIR_LIBFT) -I includes $(INC_DIR_DEBUG)

SRCNAME_DEBUG	= \
				./debug/deque_debug ./debug/state_debug

SRCNAME			= \
				./datatypes/stack ./datatypes/deque ./datatypes/deque_methods ./datatypes/array ./datatypes/state \
				./datatypes/state_swap_push ./datatypes/state_rotate ./datatypes/state_rev_rotate \
				./parser/parser ./parser/ft_split_space ./parser/parser_utils ./parser/construct_stack ./parser/ft_atoi_if_valid \
				./sorter/sort_stack_utils ./sorter/sort_manual ./sorter/sort_a_to_b ./sorter/sort_b_to_a

SRC				= $(addsuffix .c, $(SRCNAME))
OBJ				= $(addsuffix .o, $(SRCNAME))
OBJ_DEBUG		= $(addsuffix .o, $(SRCNAME_DEBUG))

RM				= rm -f
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ) $(OBJ_DEBUG) $(NAME).o
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(OBJ_DEBUG) $(NAME).o $(LINK_LIBFT) -o $(NAME)

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
	$(RM) $(OBJ) $(OBJ_DEBUG) $(NAME).o
	make clean -C $(LIBFT_DIR)

fclean_test :
	$(RM) test_deque test_array test_parser

fclean : clean fclean_test
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
