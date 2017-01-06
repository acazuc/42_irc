/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 21:35:56 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 21:45:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		main(int ac, char **av)
{
	t_env	env;

	ft_memset(&env, 0, sizeof(env));
	if (ac == 2)
		do_connect(&env, av[1], 4242);
	else if (ac == 3)
		do_connect(&env, av[1], av[2]);
}
