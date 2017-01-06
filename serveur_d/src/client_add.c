/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:00:15 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 16:06:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	client_add(t_env *env, int fd)
{
	t_client_list	*new;

	if (!(new = malloc(sizeof(*new))))
		ERROR("malloc failed");
	ft_memset(new, 0, sizeof(new));
	new->client.fd = fd;
	new->client.buf_r.lim = 0;
	new->client.buf_r.cap = BUF_SIZE;
	new->client.buf_w.lim = BUF_SIZE;
	new->client.buf_w.cap = BUF_SIZE;
	new->next = env->clients;
	env->clients = new;
}
