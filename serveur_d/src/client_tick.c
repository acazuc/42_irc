/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_tick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:25:29 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 16:02:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		client_tick(t_env *env, t_client *client)
{
	size_t	before;

	if (FD_ISSET(client->fd, &env->sets[2]))
		return (0);
	if (FD_ISSET(client->fd, &env->sets[0]))
	{
		if (client_read(client) != 1)
			return (0);
		before = BUF_SIZE + 1;
		while (before != client->buf_r.pos)
		{
			before = client->buf_r.pos;
			if (!client_interp(env, client))
				return (0);
		}
	}
	if (FD_ISSET(client->fd, &env->sets[1]))
	{
		if (client_write(client) != 1)
			return (0);
	}
	return (1);
}
