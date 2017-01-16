/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 21:35:56 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/16 17:36:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		main(int ac, char **av)
{
	t_env	env;

	ft_memset(&env, 0, sizeof(env));
	if ((env.fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		ERROR("socket() failed");
	if (ac == 2)
		env.connected = do_connect(&env, av[1], "4242");
	else if (ac == 3)
		env.connected = do_connect(&env, av[1], av[2]);
	else
		env.connected = 0;
	while (1)
	{
		looping(&env);
	}
}
