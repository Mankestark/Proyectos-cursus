NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= /bin/rm -f

LIBFT_DIR	= libft

INCLUDE_DIR	= includes

MLX_DIR		= mlx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx \
				  -framework OpenGL \
				  -framework AppKit
INCLUDES 	= -I$(INCLUDE_DIR) \
				  -I$(LIBFT_DIR) \
				  -I$(MLX_DIR)
LIBS		= -L$(LIBFT_DIR) -lft


BUILD_DIR	= build
SRC_DIR		= ./srcs
SRCS		=	so_long.c \
				checks.c \
				errors.c \
				free.c \
				ft_gnl.c \
				init_game.c \
				keys.c \
				maps.c \
				movs.c \
				floodfill.c \
				so_long_utils.c \
				
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

restart: cbuild $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(NAME): $(OBJS) libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

libs:
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)	

bonus: all

re: fclean all

cbuild:
	-$(RM) -r $(BUILD_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)	
	$(RM) $(NAME)

.PHONY: all clean fclean re