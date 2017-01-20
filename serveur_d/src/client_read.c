/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:03:38 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 12:46:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		client_read(t_client *client)
{
	ssize_t	received;
	size_t	tmp_len;

	if (client->buf_r.pos != client->buf_r.lim)
	{
		tmp_len = client->buf_r.lim - client->buf_r.pos;
		ft_memcpy(client->buf_r.data, client->buf_r.data
				+ client->buf_r.pos, tmp_len);
		client->buf_r.pos = tmp_len;
	}
	else
	{
		tmp_len = 0;
		client->buf_r.pos = 0;
	}
	if ((received = recv(client->fd, client->buf_r.data + client->buf_r.pos
					, BUF_SIZE - tmp_len, 0)) == -1)
		return (-1);
	if (received == 0)
		return (0);
	client->buf_r.pos += received;
	buffer_flip(&client->buf_r);
	return (1);
}
