SRC			= base_func.c \
			draw.c \
			extra_func.c \
			free.c \
			hooks.c \
			main.c \
			math.c \
			perspective.c \
			read.c \
			render_main.c \
			render_point.c


SRCS		= $(addprefix src/, $(SRC))
OBJS		= ${SRCS:.c=.o}

NAME		= fdf

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_PATH) -I$(MLX_PATH)
LDFLAGS		= -L$(LIBFT_PATH) -L$(MLX_PATH)
LDLIBS		= -lmlx -lft -lXext -lX11 -lm

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a
MLX_PATH	= minilibx
MLX			= $(MLX_PATH)/libmlx.a

all:		$(NAME)

$(NAME):	${OBJS} $(LIBFT) $(MLX)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} $(LDFLAGS) $(LDLIBS)

$(LIBFT):
			make -C $(LIBFT_PATH)

$(MLX):
			make -C $(MLX_PATH)

clean:
			rm -f ${OBJS}
			make -C $(LIBFT_PATH) fclean
			make -C $(MLX_PATH) clean

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re