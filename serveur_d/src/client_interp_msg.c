/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_interp_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:47:43 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 16:31:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		client_interp_msg(t_env *env, t_client *client, char *msg)
{
	if (client->chan == NULL)
	{
		if (!buffer_write_str(&client->buf_w
					, "You must join a channel with /chan\n"))
			return (0);
	}
	chan_send_msg(client->chan, msg);
	return (1);
	(void)env;
}
