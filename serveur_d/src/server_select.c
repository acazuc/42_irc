/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:28:34 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 16:00:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void	fill_sets(t_env *env)
{
	t_client_list	*clients;
	
	env->max_fd = 0;
	FD_ZERO(&env->sets[0]);
	FD_ZERO(&env->sets[1]);
	FD_ZERO(&env->sets[2]);
	FD_SET(env->fd, &env->sets[0]);
	FD_SET(env->fd, &env->sets[2]);
	if (env->fd > env->max_fd)
		env->max_fd = env->fd;
	clients = env->clients;
	while (clients)
	{
		FD_SET(clients->client.fd, &env->sets[0]);
		FD_SET(clients->client.fd, &env->sets[1]);
		FD_SET(clients->client.fd, &env->sets[2]);
		if (clients->client.fd > env->max_fd)
			env->max_fd = clients->client.fd;
		clients = clients->next;
	}
}

void	server_select(t_env *env)
{
	struct timeval	tv;

	tv.tv_sec = 0;
	tv.tv_usec = 10000;
	fill_sets(env);
	if (select(env->max_fd + 1, &env->sets[0], &env->sets[1]
				, &env->sets[2], &tv) == -1)
		ERROR("select() failed");
}
