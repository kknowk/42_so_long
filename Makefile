NAME = so_long
CC = gcc
INCLUDES_DIR = ./Includes
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)

SRCS = srcs/main.c \
	srcs/so_long_utils.c \
	srcs/move_wasd.c \
	srcs/error.c \
	srcs/setting_img_helper.c \
	srcs/error_2.c \
	srcs/map_read.c \
	srcs/pass_tansaku.c \
	srcs/pass_tannsaku_2.c \
	srcs/pass_tannsaku_item.c

OBJS = $(SRCS:%.c=%.o)

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

clean:
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
