/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chan_send_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:32:02 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 20:32:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		chan_send_msg(t_chan *chan, char *author, char *str)
{
	t_client_list	*lst;

	lst = chan->clients;
	while (lst)
	{
		if (!buffer_write_str(&lst->client->buf_w, "\e[1;37m<"))
			return (0);
		if (!buffer_write_str(&lst->client->buf_w, chan->name))
			return (0);
		if (!buffer_write_str(&lst->client->buf_w, "> ["))
			return (0);
		if (!buffer_write_str(&lst->client->buf_w, author))
			return (0);
		if (!buffer_write_str(&lst->client->buf_w, "]\e[0m: "))
			return (0);
		if (!buffer_write_str(&lst->client->buf_w, str))
			return (0);
		if (!buffer_write_str(&lst->client->buf_w, "\n"))
			return (0);
		lst = lst->next;
	}
	return (1);
}
