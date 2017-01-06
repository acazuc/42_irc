/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chan_add_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:27:17 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 20:28:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	chan_add_client(t_chan *chan, t_client *client)
{
	t_client_list	*new;

	if (!(new = malloc(sizeof(*new))))
		ERROR("malloc failed");
	new->client = client;
	new->next = chan->clients;
	chan->clients = new;
}
