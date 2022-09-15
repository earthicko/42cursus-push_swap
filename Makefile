NAME			= push_swap
LIBFT_DIR		= libft
LIBFT			= libft.a
INC_DIR_LIBFT	= -I $(LIBFT_DIR)
INC_DIR			= -I . $(INC_DIR_LIBFT) -I includes

SRCNAME_DEBUG	= \
				./datatypes/t_deque_debug

SRCNAME			= \
				./datatypes/stack ./datatypes/t_deque

SRC				= $(addsuffix .c, $(SRCNAME))
OBJ				= $(addsuffix .o, $(SRCNAME))
OBJ_DEBUG		= $(addsuffix .o, $(SRCNAME_DEBUG))

RM				= rm -f
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

all : $(NAME)

$(LIBFT) :
	make all -j 4 -C $(LIBFT_DIR)/

$(NAME) : $(OBJ) $(LIBFT)

test_deque : $(LIBFT) $(OBJ) $(OBJ_DEBUG) t_deque_main.o
	$(CC) $(CFLAGS) $(INC_DIR) $(LIBFT_DIR)/$(LIBFT) $(OBJ) $(OBJ_DEBUG) t_deque_main.o -o test_deque

%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean :
	$(RM) $(OBJ) $(OBJ_DEBUG)
	make clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
