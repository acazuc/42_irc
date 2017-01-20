/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:56:28 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 12:59:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		cmd_nick(t_env *env, t_client *client, char **data)
{
	if (!data[1])
		return (buffer_write_str(&client->buf_w, CMD_NICK_ERROR_1));
	if (ft_strlen(data[1]) > 9)
		return (buffer_write_str(&client->buf_w, CMD_NICK_ERROR_2));
	ft_memset(client->name, 0, sizeof(client->name));
	ft_memcpy(client->name, data[1], ft_strlen(data[1]));
	return (1);
	(void)env;
}
