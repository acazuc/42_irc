# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2017/01/06 15:47:37 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serveur

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast -g

INCLUDES_PATH = include/

SRCS_PATH = src/

SRCS_NAME = main.c \
			buffer_read.c \
			buffer_write.c \
			buffer_clear.c \
			buffer_flip.c \
			client_add.c \
			client_remove.c \
			client_read.c \
			client_write.c \
			client_tick.c \
			client_interp.c \
			client_interp_msg.c \
			client_interp_cmd.c \
			server_accept.c \
			server_select.c \
			server_listen.c \
			server_tick.c \
			error_quit.c \
			parse_port.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L ../libft -lft

all: odir $(NAME)

$(NAME): $(OBJS)
	@make -C ../libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@make -C ../libft clean
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@make -C ../libft fclean
	@echo " - Cleaning executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
