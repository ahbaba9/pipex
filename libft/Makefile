CC=cc
CFLAGS= -Wall -Wextra -Werror
CFILES= ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_substr.c 

OBJ = $(CFILES:.c=.o)
NAME = libft.a
LIBC = ar -rc
RM = rm -rf


all: ${NAME}

${NAME}: ${OBJ}
	${LIBC} ${NAME} ${OBJ}

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}
re: clean fclean all
