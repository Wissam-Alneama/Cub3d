NAME   = cub3D
CC     = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft
LIBS   = -Llibft -lft -lm

SRCS   = main.c error.c \
         parsing/parse_file.c parsing/parse_utils.c \
         parsing/parse_element.c parsing/parse_color.c \
		 parsing/parse_map.c parsing/map_scan.c parsing/map_check.c
OBJS   = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c cubed.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re