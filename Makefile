NAME			= push_swap
LIBFT_DIR		= libft
LIBFT			= libft.a
LINK_LIBFT		= -L $(LIBFT_DIR) $(LIBFT_DIR)/$(LIBFT)
INC_DIR_LIBFT	= -I $(LIBFT_DIR)
INC_DIR			= -I . $(INC_DIR_LIBFT) -I includes

SRCNAME_DEBUG	= \
				./datatypes/t_deque_debug

SRCNAME			= \
				./datatypes/stack ./datatypes/t_deque ./datatypes/t_array ./datatypes/t_state \
				./datatypes/t_state_swap_push ./datatypes/t_state_rotate ./datatypes/t_state_rev_rotate \
				./parser/parser ./parser/ft_split_space ./parser/parser_utils ./parser/construct_stack \
				./sorter/sort_stack ./sorter/sort_manual

SRC				= $(addsuffix .c, $(SRCNAME))
OBJ				= $(addsuffix .o, $(SRCNAME))
OBJ_DEBUG		= $(addsuffix .o, $(SRCNAME_DEBUG))

RM				= rm -f
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ) $(OBJ_DEBUG) $(NAME).o
	$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(OBJ_DEBUG) $(NAME).o $(LINK_LIBFT) -o $(NAME)

$(LIBFT) :
	make all -j 4 -C $(LIBFT_DIR)/

test_deque : $(LIBFT) $(OBJ) $(OBJ_DEBUG) t_deque_main.o
	$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(OBJ_DEBUG) t_deque_main.o $(LINK_LIBFT) -o test_deque
	./test_deque

test_array : $(LIBFT) $(OBJ) $(OBJ_DEBUG) t_array_main.o
	$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(OBJ_DEBUG) t_array_main.o $(LINK_LIBFT) -o test_array
	./test_array

test_parser : $(LIBFT) $(OBJ) $(OBJ_DEBUG) parser_main.o
	$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(OBJ_DEBUG) parser_main.o $(LINK_LIBFT) -o test_parser
	./test_parser

%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean_test :
	$(RM) t_deque_main.o t_array_main.o parser_main.o

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
