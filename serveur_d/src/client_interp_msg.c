/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_interp_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:47:43 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 20:32:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		client_interp_msg(t_env *env, t_client *client, char *msg)
{
	if (client->chan == NULL)
	{
		if (!buffer_write_str(&client->buf_w
					, "\033[1;31mYou must join a channel with "
					"/join\033[0m\n"))
			return (0);
		return (1);
	}
	if (!chan_send_msg(client->chan, client->name, msg))
		return (0);
	return (1);
	(void)env;
}
