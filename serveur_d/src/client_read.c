/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:03:38 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 16:08:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		client_read(t_client *client)
{
	char	tmp[BUF_SIZE];
	ssize_t	received;
	size_t	tmp_len;

	tmp_len = client->buf_r.lim - client->buf_r.pos;
	ft_memcpy(tmp, client->buf_r.data + client->buf_r.pos, tmp_len);
	buffer_clear(&client->buf_r);
	if ((received = recv(client->fd, client->buf_r.data
					, BUF_SIZE - tmp_len, 0)) == -1)
		return (-1);
	if (received == 0)
		return (0);
	client->buf_r.pos = received;
	if (!buffer_write(&client->buf_r, tmp, tmp_len))
		return (-1);
	return (1);
}
