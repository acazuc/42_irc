/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:10:42 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 15:19:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		client_write(t_client *client)
{
	char	tmp[BUF_SIZE];
	size_t	tmp_len;
	ssize_t	written;

	buffer_flip(&client->buf_w);
	if ((written = send(client->fd, client->buf_w.data, client->buf_w.lim, 0)) == -1)
		return (-1);
	client->buf_w.pos += written;
	tmp_len = client->buf_w.lim - client->buf_w.pos;
	ft_memcpy(tmp, client->buf_w.data, tmp_len);
	buffer_clear(&client->buf_w);
	if (!buffer_write(&client->buf_w, tmp, tmp_len))
		return (-1);
	return (1);
}
