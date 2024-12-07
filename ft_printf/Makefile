CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = printf.c put_char_str.c putnbr_base.c put_ptr.c process.c 
BONUS_SRCS = $(SRCS)
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME)

%.o: %.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus