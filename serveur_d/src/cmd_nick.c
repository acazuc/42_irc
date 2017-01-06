/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:56:28 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 18:42:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		cmd_nick(t_env *env, t_client *client, char **data)
{
	if (!data[1])
		return (buffer_write_str(&client->buf_w
					,"\033[1;31mYou must enter a nick\033[0m\n"));
	if (ft_strlen(data[1]) > 9)
		return (buffer_write_str(&client->buf_w
					, "\033[1;31mThe nick must be 9 chars long max\033[0m\n"));
	ft_memcpy(client->name, data[1], ft_strlen(data[1]));
	return (1);
	(void)env;
}
