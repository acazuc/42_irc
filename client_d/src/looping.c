/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:30:04 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/16 18:01:01 by acazuc           ###   ########.fr       */
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
		if (env->buf.pos != env->buf.lim)
			FD_SET(env->fd, &env->sets[1]);
	}
	if (select(env->maxfd, &env->sets[0], &env->sets[1], &env->sets[2]
				, NULL) == -1)
		ERROR("select() failed");
}

void	looping(t_env *env)
{
	do_select(env);
	read_stdin(env);
}
