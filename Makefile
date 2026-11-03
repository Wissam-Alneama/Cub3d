CC = cc
CFLAGS = -Wall -Wextra -Werror -lm #for math library
Name = cub3D
SRCs = main.c
OBJs = ${SRCs:.c=.o}


all: ${Name}
${Name} : ${OBJs}
	$(CC) $(CFLAGS) -o ${Name} ${OBJs}

clean:
	rm -rf ${OBJs}

fclean: clean
	rm -rf ${Name}

re: fclean all

.PHONY: all clean fclean re