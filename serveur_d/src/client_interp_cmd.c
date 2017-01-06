/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_interp_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:49:45 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 21:25:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void	do_free(char **data)
{
	int		i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		++i;
	}
	free(data);
}

int			client_interp_cmd(t_env *env, t_client *client, char *cmd)
{
	char	**data;
	int		res;

	if (!(data = ft_strsplit(cmd, ' ')))
		ERROR("strsplit failed");
	if (!data[0])
		res = 0;
	if (!ft_strcmp(data[0], "/join"))
		res = cmd_join(env, client, data);
	else if (!ft_strcmp(data[0], "/leave"))
		res =cmd_leave(env, client, data);
	else if (!ft_strcmp(data[0], "/who"))
		res = cmd_who(env, client, data);
	else if (!ft_strcmp(data[0], "/nick"))
		res = cmd_nick(env, client, data);
	else if (!ft_strcmp(data[0], "/msg"))
		res = cmd_msg(env, client, data);
	else
		res = buffer_write_str(&client->buf_w
					, "Invalid command") == 1 ? 1 : 0;
	do_free(data);
	return (res);
}
