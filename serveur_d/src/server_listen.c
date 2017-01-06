/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_listen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:43:05 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 16:00:56 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	server_listen(t_env *env)
{
	struct sockaddr_in	sock;

	if ((env->fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		ERROR("socket() failed");
	ft_memset(&sock, 0, sizeof(sock));
	sock.sin_family = AF_INET;
	sock.sin_addr.s_addr = htonl(INADDR_ANY);
	sock.sin_port = htons(env->port);
	if (bind(env->fd, (struct sockaddr*)&sock, sizeof(sock)) == -1)
		ERROR("bind() failed");
	if (listen(env->fd, 500) == -1)
		ERROR("listen() failed");
}
