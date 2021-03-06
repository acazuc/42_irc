/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:01:05 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 12:36:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	read_stdin(t_env *env)
{
	ssize_t	readed;

	if (!FD_ISSET(0, &env->sets[0]))
		return ;
	ft_memcpy(env->buf_stdin.data, env->buf_stdin.data + env->buf_stdin.pos
			, env->buf_stdin.lim - env->buf_stdin.pos);
	env->buf_stdin.pos = env->buf_stdin.lim - env->buf_stdin.pos;
	env->buf_stdin.lim = env->buf_stdin.cap;
	if (env->buf_stdin.pos == env->buf_stdin.lim)
		ERROR("stdin buffer full, aborting");
	if ((readed = read(0, env->buf_stdin.data + env->buf_stdin.pos
					, env->buf_stdin.lim - env->buf_stdin.pos)) == -1)
		ERROR("read() failed");
	if (readed == 0)
		ERROR("stdin closed");
	env->buf_stdin.pos += readed;
	env->buf_stdin.lim = env->buf_stdin.pos;
	env->buf_stdin.pos = 0;
	check_connect(env);
}
