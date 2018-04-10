# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrosset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/19 19:43:22 by agrosset          #+#    #+#              #
#    Updated: 2017/02/19 19:43:24 by agrosset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= wolf3d

CC			= gcc
FLAGS		= -Wall -Wextra -Werror -g
ACCEL_FLAG = -Ofast
FLAGSMLX	= -lmlx 
FLAGFRAMWO	= -framework OpenGL -framework AppKit

SRC_FILES	= main.c ft_map.c ft_read_doc.c ft_free_map.c \
				ft_img_put_pixel.c \
				ft_put_line.c ft_draw_line.c ft_draw_col.c \
				ft_mlx.c ft_wolf_img.c ft_wolf_move.c\
				ft_horizontal.c ft_vertical.c ft_tools_1.c ft_tools_2.c
				

OBJ			= $(SRC_FILES:.c=.o)

H_DIR		= ./includes
LIBFT_PATH	= ./libft
MLX_PATH	= ./minilibx_macos
SRC_FOLDER	= ./srcs

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m

all: $(NAME)

#$(NAME): $(OBJ) libft.a libmlx.a
#	@$(CC) $(FLAGS) $(FLAGFRAMWO) -o $@ $(OBJ) $(LIBFT_PATH)/libft.a \
	$(MLX_PATH)/libmlx.a -I $(H_DIR)
#	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

$(NAME): $(OBJ) libft.a
	@$(CC) $(FLAGS) $(FLAGSMLX) $(FLAGFRAMWO) -o $@ $(OBJ) $(LIBFT_PATH)/libft.a \
	-I $(H_DIR)
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

libft.a:
	@echo "$(DEFAULT)"
	@(cd $(LIBFT_PATH) && $(MAKE))

libmlx.a:
	@(cd $(MLX_PATH) && $(MAKE))

%.o: $(SRC_FOLDER)/%.c
	@$(CC) $(FLAGS) -c -o $@ $< -I $(H_DIR)
	@echo "$(GREEN).\c"

clean:
	@rm -rf $(OBJ)
	@(cd $(LIBFT_PATH) && $(MAKE) $@)
	@(cd $(MLX_PATH) && $(MAKE) $@)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

# (cd $(MLX_PATH) && $(MAKE) $@)
fclean:
	@rm -rf $(NAME) $(OBJ)
	@(cd $(LIBFT_PATH) && $(MAKE) $@)
	@(cd $(MLX_PATH) && $(MAKE) $@)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."
	@echo "$(RED)$(NAME)$(DEFAULT) deleted."

re: fclean all

.PHONY: clean fclean re all
