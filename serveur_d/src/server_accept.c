/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_accept.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:53:33 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 15:57:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	server_accept(t_env *env)
{
	struct sockaddr_in	sockaddr;
	socklen_t			socklen;
	int					fd;

	if ((fd = accept(env->fd, (struct sockaddr*)&sockaddr, &socklen)) == -1)
		ERROR("accept() failed");
	client_add(env, fd);
	ft_putstr("New client\n");
}
