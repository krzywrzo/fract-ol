CC = cc
CFLAGS = -Wall -Wextra -Werror -DGL_SILENCE_DEPRECATION -g -I./ -I$(MINILIBX_PATH) -I$(LIB_PATH)
SRC =  main.c win_utils.c utils.c math_utils.c fractol_utils.c events.c
OBJS = $(SRC:.c=.o)
NAME = fractol
AR = ar rcs

MINILIBX_PATH = minilibx-linux
MINILBX = $(MINILIBX_PATH)/
MLX_LIBS = -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm -lbsd

# libft
LIB_PATH = ./libft
LIBFT = $(LIB_PATH)/libft.a
HEADER = fractol.h

all: $(LIBFT) minilibx $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLX_LIBS) -o $(NAME)

$(LIBFT):
	make -C $(LIB_PATH) all

minilibx:
	make -C $(MINILIBX_PATH)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIB_PATH) clean
	make -C $(MINILIBX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
