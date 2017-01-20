/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:02:08 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 13:02:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int	send_msg_2(t_client *src, t_client *dst, char **data)
{
	int		i;

	if (!buffer_write_str(&dst->buf_w, "\033[1;37mFrom ["))
		return (0);
	if (!buffer_write_str(&dst->buf_w, src->name))
		return (0);
	if (!buffer_write_str(&dst->buf_w, "]\033[0m: "))
		return (0);
	i = 2;
	while (data[i])
	{
		if (!buffer_write_str(&dst->buf_w, data[i]))
			return (0);
		if (!buffer_write_str(&dst->buf_w, " "))
			return (0);
		++i;
	}
	buffer_write_str(&dst->buf_w, "\n");
	return (1);
}

static int	send_msg(t_client *src, t_client *dst, char **data)
{
	int		i;

	if (!buffer_write_str(&src->buf_w, "\033[1;37mTo ["))
		return (0);
	if (!buffer_write_str(&src->buf_w, dst->name))
		return (0);
	if (!buffer_write_str(&src->buf_w, "]\033[0m: "))
		return (0);
	i = 2;
	while (data[i])
	{
		if (!buffer_write_str(&src->buf_w, data[i]))
			return (0);
		if (!buffer_write_str(&src->buf_w, " "))
			return (0);
		++i;
	}
	buffer_write_str(&src->buf_w, "\n");
	return (send_msg_2(src, dst, data));
}

int			cmd_msg(t_env *env, t_client *client, char **data)
{
	t_client_list	*lst;

	if (!data[1])
		return (buffer_write_str(&client->buf_w, CMD_MSG_ERROR_1));
	if (!data[2])
		return (buffer_write_str(&client->buf_w, CMD_MSG_ERROR_2));
	lst = env->clients;
	while (lst)
	{
		if (!ft_strcmp(data[1], lst->client->name))
			return (send_msg(client, lst->client, data));
		lst = lst->next;
	}
	return (buffer_write_str(&client->buf_w, CMD_MSG_ERROR_3));
}
