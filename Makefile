CC = cc
CFLAGS = -Wall -Wextra -Werror -DGL_SILENCE_DEPRECATION -I./ -I$(MINILIBX_PATH) -I$(LIB_PATH)
GNL_SRC = gnl/get_next_line.c gnl/get_next_line_utils.c
SRC =  main.c win_utils.c utils.c math_utils.c fractol_utils.c $(GNL_SRC)
OBJS = $(SRC:.c=.o)
NAME = fractol
AR = ar rcs

# minilibx (macOS)
MINILIBX_PATH = minilibx_macos
MINILBX = $(MINILIBX_PATH)/
MLX_LIBS = -L$(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit

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
