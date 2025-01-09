NAME= push_swap

CHECKER= checker

SRCS =  push_swap.c actions_rotate.c actions_swap.c filtered_argc.c ft_manage_stack.c ft_manage_stack_utils.c ft_split.c\
		libft_func.c simple_sort.c stack_operations.c large_sort.c Quick_sort.c ft_push_back.c ft_push_back_utils.c
SRCS_BONUS = ./bonus_checker/checker.c\
				./bonus_checker/checker_utils.c\
				actions_rotate.c\
				actions_swap.c\
				ft_manage_stack.c\
				ft_manage_stack_utils.c\
				filtered_argc.c\
				ft_split.c\

SRCS_GNL= ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

OB_BONUS= $(SRCS_BONUS:.c=.o)

OBJS_GNL= $(SRCS_GNL:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME): $(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	rm -rf ${OBJS}

bonus : $(CHECKER)

$(CHECKER): $(OB_BONUS) $(OBJS_GNL)
	$(CC) $(CFLAGS) $(OB_BONUS) $(OBJS_GNL) -o $(CHECKER)
	rm -rf ${OB_BONUS} ${OBJS_GNL}

clean :
	rm -rf ${OBJS} ${OB_BONUS} ${OBJS_GNL}

fclean : clean
	rm -rf $(NAME) $(CHECKER)

re : fclean all
