CC      = cc
CFLAGS  = -Wall -Wextra -Werror

PROG    = pipex
PROG_B  = pipex_bonus

SRCS    = pipex.c utils.c freepip.c
OBJS    = $(SRCS:.c=.o)

SRCS_B  = pipex_bonus.c freepip.c utils.c utils_bonus.c
OBJS_B  = $(SRCS_B:.c=.o)

HEADER  = pipex.h

LIBFT_A = libft/libft.a

all: $(PROG)
	

bonus: $(PROG_B)

$(PROG): $(OBJS) 
	@make -C libft && make && make clean
	@$(CC) $(CFLAGS) $(OBJS)  $(LIBFT_A) -o $(PROG)

$(PROG_B): $(OBJS_B) 
	@make -C libft && make && make clean
	@$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT_A) -o $(PROG_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(PROG) $(PROG_B) $(LIBFT_A)

re: fclean all

.PHONY: all clean fclean re bonus