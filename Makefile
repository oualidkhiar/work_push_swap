NAME = push_swap

SRCS=  push_swap.c actions_rotate.c actions_swap.c filtered_argc.c ft_manage_stack.c ft_manage_stack_utils.c ft_split.c\
		libft_func.c simple_sort.c stack_operations.c large_sort.c Quick_sort.c ft_push_back.c ft_push_back_utils.c\

OBJS = $(SRCS:.c=.o)

SRCS_BONUS= ./checker/checker.c

OBJS_BONUS= $(SRCS_BONUS:.c=.o)

SRCS_GNL= ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

OBJS_GNL= $(SRCS_GNL:.c=.o)
%.o : %.c
		${CC} ${CFLAGS} -c $< -o $@

CC = cc
CFLAGS = -Wall -Wextra -Werror


all : $(NAME)


${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	rm -rf ${OBJS}

bonus : $(OBJS_GNL) $(OBJS) $(OBJS_BONUS)

${NAME}: $(OBJS) $(OBJS_GNL) ${OBJS_BONUS}
	${CC} ${CFLAGS} ${SRCS_GNL} ${SRCS_BONUS} -o ${NAME}
	rm -rf ${OBJS}

clean :
	rm -f ${OBJS} ${OBJS_BONUS} ${OBJS_GNL}

fclean : clean
	rm -f $(NAME)

re : fclean all
