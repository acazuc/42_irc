/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_who.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:45:06 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 12:58:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		cmd_who(t_env *env, t_client *client, char **data)
{
	t_client_list	*lst;

	if (!client->chan)
		return (buffer_write_str(&client->buf_w, CMD_WHO_ERROR));
	lst = client->chan->clients;
	while (lst)
	{
		if (!buffer_write_str(&client->buf_w, lst->client->name))
			return (0);
		if (lst->next)
		{
			if (!buffer_write_str(&client->buf_w, ", "))
				return (0);
		}
		else if (!buffer_write_str(&client->buf_w, "\n"))
			return (0);
		lst = lst->next;
	}
	return (1);
	(void)data;
	(void)env;
}
