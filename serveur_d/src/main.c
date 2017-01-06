/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:15:27 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 16:00:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int	main(int ac, char **av)
{
	t_env	env;

	ft_memset(&env, 0, sizeof(env));
	if (ac != 2)
		ERROR("Invalid parameter (./serveur <port>)");
	parse_port(&env, av[1]);
	server_listen(&env);
	while (1)
	{
		server_select(&env);
		server_tick(&env);
		if (FD_ISSET(env.fd, &env.sets[0]))
			server_accept(&env);
	}
}
