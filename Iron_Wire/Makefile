NAME = fdf
CC = cc
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS = $(LIBFT) $(MLX) -lXext -lX11 -lm

SRCS = parsing.c parsing_utils.c main.c mlx_op.c operations.c hooks.c clean_up.c mlx_op1.c operation1.c parsing1.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re