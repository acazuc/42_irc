/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 21:46:03 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/16 17:34:05 by acazuc           ###   ########.fr       */
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

int			do_connect(t_env *env, char *host, char *port)
{
	struct hostent		*hostent;
	struct sockaddr_in	sock;

	if (!valid_port(port))
	{
		ft_putstr("\033[1;31mInvalid port\033[0m\n");
		return (0);
	}
	if (!(hostent = gethostbyname(host))
			|| !inet_aton(hostent->h_addr, &sock.sin_addr))
	{
		ft_putstr("\033[1;31mInvalid ip address\033[0m\n");
		return (0);
	}
	sock.sin_port = htons(atoi(port));
	sock.sin_family = AF_INET;
	if (connect(env->fd, (struct sockaddr*)&sock, sizeof(sock)) == -1)
	{
		ft_putstr("\033[1;31mFailed to connect\033[0m\n");
		return (0);
	}
	return (1);
}
