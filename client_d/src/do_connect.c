/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 21:46:03 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/17 17:10:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	valid_port(char *port)
{
	if (!ft_strisdigit(port))
		return (0);
	while (port[0] == '0')
		port++;
	if (ft_strlen(port) > 5 || ft_strlen(port) < 1)
		return (0);
	if (ft_atoi(port) > USHRT_MAX)
		return (0);
	return (1);
}

static int	do_do(t_env *env, struct sockaddr_in *sock)
{
	if (env->fd)
		close(env->fd);
	if ((env->fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		ERROR("socket() failed");
	if (connect(env->fd, (struct sockaddr*)sock, sizeof(*sock)) == -1)
	{
		ft_putstr("\033[1;31mFailed to connect\033[0m\n");
		return (0);
	}
	return (1);
}

void		do_connect(t_env *env, char *host, char *port)
{
	struct hostent		*hostent;
	struct sockaddr_in	sock;

	env->connected = 0;
	if (!valid_port(port))
	{
		ft_putstr("\033[1;31mInvalid port\033[0m\n");
		return ;
	}
	if (!(hostent = gethostbyname(host)))
	{
		ft_putstr("\033[1;31mInvalid ip address\033[0m\n");
		return ;
	}
	ft_memset(&sock, 0, sizeof(sock));
	ft_memcpy(&sock.sin_addr, hostent->h_addr, hostent->h_length);
	sock.sin_port = htons(atoi(port));
	sock.sin_family = AF_INET;
	if (!do_do(env, &sock))
	{
		return ;
	}
	env->connected = 1;
	env->buf_write.pos = 0;
	env->buf_write.lim = BUF_SIZE;
}
