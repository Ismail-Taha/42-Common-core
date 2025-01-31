CC      = cc
CFLAGS  = -Wall -Wextra -Werror -fsanitize=address -g3

PROG    = push_swap
# PROG_B  = pipex_bonus

SRCS    = push.c costs_getter.c pos_getter.c helpers.c inp_checker.c op.c op1.c op2.c stack_op.c sort_instruction.c sort_instruction1.c
OBJS    = $(SRCS:.c=.o)

# SRCS_B  = pipex_bonus.c freepip.c utils.c utils_bonus.c
# OBJS_B  = $(SRCS_B:.c=.o)

HEADER  = push.h

LIBFT_A = Libft/libft.a

all: $(PROG)
	

# bonus: $(PROG_B)

$(PROG): $(OBJS) 
	@cd Libft && make && make clean
	$(CC) $(CFLAGS) $(OBJS)  $(LIBFT_A) -o $(PROG)

# $(PROG_B): $(OBJS_B) 
# 	@cd libft && make && make clean
# 	$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT_A) -o $(PROG_B)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(PROG) $(LIBFT_A)

re: fclean all

.PHONY: all clean fclean re bonus