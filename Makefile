# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/30 22:21:38 by jdavin            #+#    #+#              #
#    Updated: 2016/04/18 17:48:21 by jdavin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INC_DIR = ./

SRC_DIR = .src/

SRC_FILES = main.c \
	    	put_error.c \
	    	ft_init.c \
	    	key_hook.c

O_FILES = $(SRC_FILES:.c=.o)

CC = clang

CC_FLAGS = -Wall -Werror -Wextra -lm

I_LIBFT = -I libft/ -I minilibx_macos/

LIBFT = -L libft $(I_LIBFT) -lft

LIBLX = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@$(CC) $(CC_FLAGS) -o $(NAME) $^ -I $(INC_DIR) $(LIBFT) $(LIBLX)
	@echo "$(NAME) created."

%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS)  -I$(INC_DIR) -o $@ -c $< $(I_LIBFT)

clean:
	@make clean -C libft
	@make clean -C minilibx_macos
	@rm -f $(O_FILES)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo $(NAME) Deleted.

re: fclean all

.PHONY: all clean fclean re