/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:11:14 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 14:26:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		buffer_read(t_buffer *buffer, void *data, size_t len)
{
	if (buffer->pos + len > buffer->lim)
		return (0);
	ft_memcpy(data, buffer->data + buffer->pos, len);
	buffer->pos += len;
	return (1);
}
