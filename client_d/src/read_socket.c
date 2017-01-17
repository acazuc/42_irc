/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_socket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:22:50 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/17 14:29:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	read_socket(t_env *env)
{
	ssize_t	readed;

	if ((readed = recv(env->fd, env->buf_read.data, BUF_SIZE, 0)) == -1)
		ERROR("recv() failed");
	else if (readed == 0)
	{
		ft_putstr("\033[1;31mConnection closed\033[0m\n");
		env->connected = 0;
		return ;
	}
	readed = write(1, env->buf_read.data, readed);
}
