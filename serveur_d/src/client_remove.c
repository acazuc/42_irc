/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:07:02 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 14:26:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	client_remove(t_env *env, t_client *client)
{
	t_client_list	*lst;
	t_client_list	*prv;

	prv = NULL;
	lst = env->clients;
	while (lst)
	{
		if (&lst->client == client)
		{
			if (prv)
				prv->next = lst->next;
			else
				env->clients = lst->next;
			free(client);
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
}
