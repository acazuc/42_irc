/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:07:02 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/17 17:00:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void		remove_from_rooms(t_env *env, t_client *client)
{
	t_chan_list	*lst;
	t_chan_list	*nxt;

	lst = client->chans;
	while (lst)
	{
		chan_remove_client(env, lst->chan, client);
		nxt = lst->next;
		free(lst);
		lst = nxt;
	}
}

void			client_remove(t_env *env, t_client *client)
{
	t_client_list	*lst;
	t_client_list	*prv;

	close(client->fd);
	prv = NULL;
	lst = env->clients;
	while (lst)
	{
		if (lst->client == client)
		{
			if (prv)
				prv->next = lst->next;
			else
				env->clients = lst->next;
			remove_from_rooms(env, client);
			free(client);
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
}
