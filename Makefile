NAME = so_long

SRCS = so_long.c frees.c error.c map_init.c map_read.c \
		map_validation.c map_validation_aux.c render.c \
		input.c input_aux.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I/usr/include -Imlx -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -s -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(MAKE) --no-print-directory -s -C $(MLX_DIR) > /dev/null 2>&1
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)
	@echo "SO LONG is ready!!"
	@echo "Usage: ./so_long maps/map1.ber"

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@$(MAKE) --no-print-directory -s clean -C $(MLX_DIR) > /dev/null 2>&1
	@$(RM) $(OBJS)
	@echo "Files successfully removed."

fclean: clean
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "Goodbye!"

re: fclean all

.PHONY: all clean fclean re