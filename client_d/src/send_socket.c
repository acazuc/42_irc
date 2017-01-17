/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_socket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:14:11 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/17 14:27:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_socket(t_env *env)
{
	ssize_t	sended;

	env->buf_write.lim = env->buf_write.pos;
	env->buf_write.pos = 0;
	if ((sended = send(env->fd, env->buf_write.data, env->buf_write.lim, 0))
			== -1)
		ERROR("send() failed");
	env->buf_write.pos += sended;
	ft_memcpy(env->buf_write.data, env->buf_write.data + env->buf_write.pos
			, env->buf_write.lim - env->buf_write.pos);
	env->buf_write.pos = env->buf_write.lim - env->buf_write.pos;
	env->buf_write.lim = env->buf_write.cap;
}
