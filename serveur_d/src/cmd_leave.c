/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_leave.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:35:13 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 13:21:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int		cyalol(t_client *client)
{
	if (!client->chans)
	{
		client->chan = NULL;
		return (buffer_write_str(&client->buf_w, CMD_LEAVE_ERROR_1));
	}
	client->chan = client->chans->chan;
	if (!(buffer_write_str(&client->buf_w, CMD_LEAVE_ERROR_2_1)))
		return (0);
	if (!(buffer_write_str(&client->buf_w, client->chan->name)))
		return (0);
	if (!(buffer_write_str(&client->buf_w, CMD_LEAVE_ERROR_2_2)))
		return (0);
	return (1);
}

static int		leave(t_env *env, t_client *client, char *c)
{
	t_chan_list	*lst;
	t_chan_list	*prv;

	lst = client->chans;
	prv = NULL;
	while (lst)
	{
		if (!ft_strcmp(c, lst->chan->name))
		{
			chan_remove_client(env, lst->chan, client);
			if (prv)
				prv->next = lst->next;
			else
				client->chans = lst->next;
			free(lst);
			return (cyalol(client));
		}
		prv = lst;
		lst = lst->next;
	}
	return (buffer_write_str(&client->buf_w, CMD_LEAVE_ERROR_3));
}

int				cmd_leave(t_env *env, t_client *client, char **data)
{
	char	s[10];

	if (!data[1])
	{
		if (!client->chan)
			return (buffer_write_str(&client->buf_w, CMD_LEAVE_ERROR_4));
		ft_strcpy(s, client->chan->name);
	}
	else
	{
		if (data[1][0] != '#')
			return (buffer_write_str(&client->buf_w, CMD_LEAVE_ERROR_5));
		ft_strcpy(s, data[1]);
	}
	return (leave(env, client, s));
	(void)env;
}
