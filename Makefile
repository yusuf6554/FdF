SRC			= main.c \
			hooks.c \
			base_func.c \
			colors.c \
			colors2.c \
			shapes.c


SRCS		= $(addprefix src/, $(SRC))
OBJS		= ${SRCS:.c=.o}

NAME		= fdf

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS		= -L$(LIBFT_PATH) -L$(MLX_PATH)
LDLIBS		= -lmlx -lft -lXext -lX11 -lm

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a
MLX_PATH	= minilibx
MLX			= $(MLX_PATH)/libmlx.a

$(NAME):	$(LIBFT) $(MLX) ${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} $(LDFLAGS) $(LDLIBS)

$(LIBFT):
			make -C $(LIBFT_PATH)

$(MLX):
			make -C $(MLX_PATH)

all:		$(NAME)

clean:
			rm -f ${OBJS}
			make -C $(LIBFT_PATH) fclean
			make -C $(MLX_PATH) clean

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re