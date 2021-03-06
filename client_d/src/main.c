/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 21:35:56 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/17 14:45:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	do_init_buf(t_env *env)
{
	env->buf_stdin.cap = BUF_SIZE;
	env->buf_write.cap = BUF_SIZE;
	env->buf_write.lim = BUF_SIZE;
}

int			main(int ac, char **av)
{
	t_env	*env;

	if (!(env = malloc(sizeof(*env))))
		ERROR("malloc() failed");
	ft_memset(env, 0, sizeof(*env));
	if (ac == 2)
		do_connect(env, av[1], "4242");
	else if (ac == 3)
		do_connect(env, av[1], av[2]);
	do_init_buf(env);
	while (1)
	{
		looping(env);
	}
}
