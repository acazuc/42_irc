/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_tick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:59:38 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 16:42:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	server_tick(t_env *env)
{
	t_client_list	*nxt;
	t_client_list	*lst;

	lst = env->clients;
	while (lst)
	{
		nxt = lst->next;
		if (!client_tick(env, lst->client))
		{
			ft_putstr("client quit\n");
			client_remove(env, lst->client);
		}
		lst = nxt;
	}
}
