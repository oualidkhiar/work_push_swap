NAME = push_swap

SRCS=  push_swap.c actions_rotate.c actions_swap.c filtered_argc.c ft_manage_stack.c ft_manage_stack_utils.c ft_split.c libft_func.c simple_sort.c stack_operations.c large_sort.c Quick_sort.c ft_push_back.c ft_push_back_utils.c\

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)


${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	rm -rf ${OBJS}


clean :
	rm -f ${OBJS}

fclean : clean
	rm -f $(NAME)

re : fclean all
