/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_tick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:01:21 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 16:08:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		client_tick(t_env *env, t_client *client)
{
	if (FD_ISSET(client->fd, &env->sets[2]))
		return (0);
	if (FD_ISSET(client->fd, &env->sets[0]))
	{
		if (client_read(client) != 1)
			return (0);
		if (!client_interp(env, client))
			return (0);
	}
	if (FD_ISSET(client->fd, &env->sets[1]))
	{
		if (client_write(client) != 1)
			return (0);
	}
	return (1);
}
