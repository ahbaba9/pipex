NAME = pipex

CC = CC

CFLAGS = -Wall -Wextra -Werror

CFILES = 	pipex.c \
			pathfinder.c \
			execute_cmds.c \
			ft_calloc.c \
			ft_split.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_substr.c \
			ft_bzero.c \
			ft_strnstr.c 
			
			
OBJ = $(CFILES:.c=.o)

#LIBC = ar -rc


RM = rm -rf

all: ${NAME}

${NAME}: ${OBJ}
	${CC} $(CFLAGS) $^ -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: clean fclean all