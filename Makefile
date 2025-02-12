SRCS		= main.c

OBJS		= ${SRCS:.c=.o}

NAME		= fdf

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a
MLX_PATH	= minilibx
MLX			= $(MLX_PATH)/libmlx.a

$(NAME):	$(LIBFT) $(MLX) ${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${MLX}

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