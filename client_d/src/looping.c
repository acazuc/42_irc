/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:30:04 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 12:42:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void		do_select(t_env *env)
{
	FD_ZERO(&env->sets[0]);
	FD_ZERO(&env->sets[1]);
	FD_ZERO(&env->sets[2]);
	env->maxfd = 1;
	FD_SET(0, &env->sets[0]);
	FD_SET(0, &env->sets[2]);
	if (env->connected)
	{
		env->maxfd = env->fd + 1;
		FD_SET(env->fd, &env->sets[0]);
		FD_SET(env->fd, &env->sets[2]);
		if (env->buf_write.pos)
			FD_SET(env->fd, &env->sets[1]);
	}
	if (select(env->maxfd, &env->sets[0], &env->sets[1], &env->sets[2]
				, NULL) == -1)
		ERROR("select() failed");
}

void			looping(t_env *env)
{
	do_select(env);
	if (FD_ISSET(0, &env->sets[2]))
		ERROR("broken stdin");
	read_stdin(env);
	if (env->connected)
	{
		if (FD_ISSET(env->fd, &env->sets[2]))
		{
			ft_putstr("\033[1;31mConnection dropped\033[0m\n");
			env->connected = 0;
			return ;
		}
		if (FD_ISSET(env->fd, &env->sets[1]))
			send_socket(env);
		if (FD_ISSET(env->fd, &env->sets[0]))
			read_socket(env);
	}
}
