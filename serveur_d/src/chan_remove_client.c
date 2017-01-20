/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chan_remove_client.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:17:33 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 12:50:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void	do_remove(t_env *env, t_chan *chan)
{
	t_chan_list		*lst;
	t_chan_list		*prv;

	lst = env->chans;
	prv = NULL;
	while (lst)
	{
		if (lst->chan == chan)
		{
			if (prv)
				prv->next = lst->next;
			else
				env->chans = lst->next;
			free(lst->chan);
			free(lst);
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
}

void		chan_remove_client(t_env *env, t_chan *chan, t_client *client)
{
	t_client_list	*lst;
	t_client_list	*prv;

	prv = NULL;
	lst = chan->clients;
	while (lst)
	{
		if (lst->client == client)
		{
			if (prv)
				prv->next = lst->next;
			else
				chan->clients = lst->next;
			free(lst);
			if (!chan->clients)
				do_remove(env, chan);
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
}
