/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chan_add_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:27:17 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/22 12:28:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int	has_client(t_chan *chan, t_client *client)
{
	t_client_list	*lst;

	lst = chan->clients;
	while (lst)
	{
		if (lst->client == client)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void		chan_add_client(t_chan *chan, t_client *client)
{
	t_client_list	*new;

	if (has_client(chan, client))
		return ;
	if (!(new = malloc(sizeof(*new))))
		ERROR("malloc failed");
	new->client = client;
	new->next = chan->clients;
	chan->clients = new;
}
