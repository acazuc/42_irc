/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:09:30 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 14:26:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		buffer_write(t_buffer *buffer, void *data, size_t len)
{
	if (len + buffer->pos > buffer->lim)
		return (0);
	ft_memcpy(buffer->data + buffer->pos, data, len);
	buffer->pos += len;
	return (1);
}
