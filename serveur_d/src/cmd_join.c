/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:44:27 by acazuc            #+#    #+#             */
/*   Updated: 2017/02/26 08:04:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static t_chan	*chan_get(t_env *env, char *name)
{
	t_chan_list	*lst;

	lst = env->chans;
	while (lst)
	{
		if (!ft_strcmp(name, lst->chan->name))
			return (lst->chan);
		lst = lst->next;
	}
	return (NULL);
}

static int		is_in(t_client *client, t_chan *chan)
{
	t_chan_list	*lst;

	lst = client->chans;
	while (lst)
	{
		if (lst->chan == chan)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static void		join_chan(t_client *client, t_chan *chan)
{
	t_chan_list	*new;

	client->chan = chan;
	if (is_in(client, chan))
		return ;
	if (!(new = malloc(sizeof(*new))))
		ERROR("malloc failed");
	new->chan = chan;
	new->next = client->chans;
	client->chans = new;
}

int				cmd_join(t_env *env, t_client *client, char **data)
{
	t_chan	*chan;

	if (!data[1])
		return (buffer_write_str(&client->buf_w, CMD_JOIN_ERROR_1));
	if (data[1][0] != '#')
		return (buffer_write_str(&client->buf_w, CMD_JOIN_ERROR_2));
	if (ft_strlen(data[1]) > 9)
		return (buffer_write_str(&client->buf_w, CJE3));
	chan = chan_get(env, data[1]);
	if (!chan)
		chan = chan_create(env, data[1]);
	chan_add_client(chan, client);
	join_chan(client, chan);
	return (1);
}
