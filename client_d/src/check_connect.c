/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_connect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:26:53 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/17 17:36:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static ssize_t	get_pos(t_env *env)
{
	void	*pos;

	pos = memchr(env->buf_stdin.data, '\n', env->buf_stdin.lim);
	if (!pos)
		return (-1);
	return ((unsigned long)pos - (unsigned long)env->buf_stdin.data);
}

static void		flush_to(t_env *env, ssize_t pos)
{
	size_t	len;

	len = pos + 1;
	if (!env->connected)
	{
		ft_putstr("\033[1;31mYou must be connected first\033[0m\n");
		env->buf_stdin.pos += len;
		return ;
	}
	if (env->buf_write.lim - env->buf_write.pos < len)
		len = env->buf_write.lim - env->buf_write.pos;
	ft_memcpy(env->buf_write.data + env->buf_write.pos
			, env->buf_stdin.data, len);
	env->buf_write.pos += len;
	env->buf_stdin.pos += len;
}

static void		free_data(char **data)
{
	size_t	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		++i;
	}
	free(data);
}

static void		parse_cmd(t_env *env, char *cmd)
{
	char	**data;

	if (!(data = ft_strsplit(cmd, ' ')))
		ERROR("ft_strsplit() failed");
	free(cmd);
	if (!data[0] || !data[1])
	{
		ft_putstr("\033[1;31mYou must specify a host\033[0m\n");
		free_data(data);
		return ;
	}
	if (!data[2])
		do_connect(env, data[1], "4242");
	else
		do_connect(env, data[1], data[2]);
	free_data(data);
}

void			check_connect(t_env *env)
{
	ssize_t		pos;
	char		*cmd;

	if ((pos = get_pos(env)) == -1)
		return ;
	if (pos < 8)
	{
		flush_to(env, pos);
		return ;
	}
	if (memcmp(env->buf_stdin.data, "/connect", 8))
	{
		flush_to(env, pos);
		return ;
	}
	if (!(cmd = malloc(sizeof(*cmd) * (pos + 1))))
		ERROR("malloc() failed");
	ft_memcpy(cmd, env->buf_stdin.data, pos);
	cmd[pos] = '\0';
	env->buf_stdin.pos += pos + 1;
	ft_memcpy(env->buf_stdin.data, env->buf_stdin.data + env->buf_stdin.pos
			, env->buf_stdin.lim - env->buf_stdin.pos);
	env->buf_stdin.lim -= pos + 1;
	env->buf_stdin.pos = 0;
	parse_cmd(env, cmd);
}
