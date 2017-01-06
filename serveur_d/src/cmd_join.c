/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:44:27 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 20:52:28 by acazuc           ###   ########.fr       */
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

static void		join_chan(t_client *client, t_chan *chan)
{
	t_chan_list	*new;

	if (!(new = malloc(sizeof(*new))))
		ERROR("malloc failed");
	new->chan = chan;
	new->next = client->chans;
	client->chans = new;
	client->chan = chan;
}

int				cmd_join(t_env *env, t_client *client, char **data)
{
	t_chan	*chan;

	if (!data[1])
		return (buffer_write_str(&client->buf_w
					, "\033[1;31mYou must join a channel first\033[0m\n"));
	if (data[1][0] != '#')
		return (buffer_write_str(&client->buf_w
					, "\033[1;31mChan name must start with #\033[0m\n"));
	if (ft_strlen(data[1]) > 9)
		return (buffer_write_str(&client->buf_w
					, "\033[1;31mChannel name must be less than "
					"chars\033[0m\n"));
	chan = chan_get(env, data[1]);
	if (!chan)
		chan = chan_create(env, data[1]);
	chan_add_client(chan, client);
	join_chan(client, chan);
	return (1);
}
