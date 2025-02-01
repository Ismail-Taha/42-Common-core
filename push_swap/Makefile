CC      = cc
CFLAGS  = -Wall -Wextra -Werror 
PROG    = push_swap
PROG_B  = checker
SRCS    =  push_s/costs_getter.c push_s/pos_getter.c push_s/helpers.c push_s/inp_checker.c push_s/op.c push_s/op1.c push_s/op2.c push_s/stack_op.c push_s/sort_instruction.c push_s/sort_instruction1.c push_s/push.c
OBJS    = $(SRCS:.c=.o)

SRCS_B  =  push_s/costs_getter.c push_s/pos_getter.c push_s/helpers.c push_s/inp_checker.c push_s/op.c push_s/op1.c push_s/op2.c push_s/stack_op.c push_s/sort_instruction.c push_s/sort_instruction1.c push_checker/Checker.c push_checker/get_next_line.c push_checker/get_next_line_utils.c
OBJS_B  = $(SRCS_B:.c=.o)

HEADER  = push.h

LIBFT_A = Libft/libft.a

all: $(PROG)
	

bonus: $(PROG_B)


$(PROG): $(OBJS)
	make -C Libft && make -C Libft clean
	$(CC) $(CFLAGS) $(OBJS)  $(LIBFT_A) -o $(PROG)

$(PROG_B): $(OBJS_B) 
	make -C Libft && make -C Libft clean
	$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT_A) -o $(PROG_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(PROG) $(LIBFT_A) $(PROG_B)

re: fclean all

.PHONY: all clean fclean re bonus