/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_connect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:26:53 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/16 18:30:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static ssize_t	get_pos(t_env *env)
{
	void	*pos;

	pos = memchr(env->buf_stdin.data, '\t', env->buf_stdin.pos);
	if (!pos)
		return (-1);
	return (pos - env->buf_stdin.data);
}

void	check_connect(t_env *env)
{
	ssize_t		pos;

	if ((pos = get_pos(env) == -1))
		return ;
}
