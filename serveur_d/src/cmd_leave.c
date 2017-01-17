/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_leave.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:35:13 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/17 17:11:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int		cyalol(t_client *client)
{
	if (!client->chans)
	{
		client->chan = NULL;
		return (buffer_write_str(&client->buf_w
					, "\033[1;32mYou are now in no room\033[0m\n"));
	}
	client->chan = client->chans->chan;
	if (!(buffer_write_str(&client->buf_w
					, "\033[1;32mYou are now in ")))
		return (0);
	if (!(buffer_write_str(&client->buf_w, client->chan->name)))
		return (0);
	if (!(buffer_write_str(&client->buf_w
					, " chan\033[0m\n")))
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
	return (buffer_write_str(&client->buf_w
				, "\033[1;31mUnknown chan\033[0m\n"));
}

int				cmd_leave(t_env *env, t_client *client, char **data)
{
	char	s[10];

	if (!data[1])
	{
		if (!client->chan)
			return (buffer_write_str(&client->buf_w
						, "\033[1;31mYou're not into a room\033[0m\n"));
		ft_strcpy(s, client->chan->name);
	}
	else
	{
		if (data[1][0] != '#')
			return (buffer_write_str(&client->buf_w
						, "\033[1;31mInvalid chan name\033[0m\n"));
		ft_strcpy(s, data[1]);
	}
	return (leave(env, client, s));
	(void)env;
}
