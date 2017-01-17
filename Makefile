# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2017/01/17 18:31:28 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: libft client serveur

libft:
	@echo " - Making libft"
	@make -C libft

client:
	@echo " - Making client"
	@make -C client_d
	@ln -sf client_d/client client

serveur:
	@echo " - Making serveur"
	@make -C serveur_d
	@ln -sf serveur_d/serveur serveur

clean:
	@echo " - Cleaning libft"
	@make -C libft clean
	@echo " - Cleaning client"
	@make -C client_d clean
	@echo " - Cleaning server"
	@make -C serveur_d clean

fclean:
	@echo " - Cleaning libft executable"
	@make -C libft fclean
	@echo " - Cleaning client executable"
	@make -C client_d fclean
	@echo " - Cleaning server executable"
	@make -C serveur_d fclean
	@rm -f client
	@rm -f serveur

re: fclean all

.PHONY: libft client server clean fclean re
