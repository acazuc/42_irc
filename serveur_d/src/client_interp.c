/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_interp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:27:29 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 16:01:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void	get_pos(void *data, size_t len, size_t *val)
{
	void	*re;

	re = ft_memchr(data, '\n', len);
	if (re == NULL)
		*val = BUF_SIZE + 1;
	else
		*val = re - data;
}

int			client_interp(t_env *env, t_client *client)
{
	size_t	end_pos;
	char	*cmd;

	get_pos(client->buf_r.data + client->buf_r.pos
			, client->buf_r.lim - client->buf_r.pos, &end_pos);
	if (end_pos == BUF_SIZE + 1)
	{
		if (client->buf_r.lim == client->buf_r.cap)
			return (0);
		return (1);
	}
	if (!(cmd = malloc(sizeof(*cmd) * (end_pos + 1))))
		ERROR("malloc failed");
	if (!(buffer_read(&client->buf_r, cmd, end_pos + 1)))
		return (0);
	cmd[end_pos] = '\0';
	if (cmd[0] == '/')
		return (client_interp_cmd(env, client, cmd));
	return (client_interp_msg(env, client, cmd));
}
