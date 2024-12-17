# Compiler and Flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror #-fsanitize=address -g3

# Program Names
PROG    = pipex
PROG_B  = pipex_bonus

# Source and Object Files
SRCS    = pipex.c utils.c
OBJS    = $(SRCS:.c=.o)

SRCS_B  = pipex_bonus.c utils.c utils_bonus.c
OBJS_B  = $(SRCS_B:.c=.o)

# Header Files
HEADER  = pipex.h

# Libft Static Library
LIBFT_A = ./libft.a

# Targets
all: $(PROG)

bonus: $(PROG_B)

$(PROG): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(PROG)

$(PROG_B): $(OBJS_B) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT_A) -o $(PROG_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(PROG) $(PROG_B)

re: fclean all

.PHONY: all clean fclean re bonus