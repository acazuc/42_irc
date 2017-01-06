/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chan_remove_client.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:17:33 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 17:19:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	chan_remove_client(t_chan *chan, t_client *client)
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
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
}
