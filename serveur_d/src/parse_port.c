/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_port.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:18:53 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 14:22:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int	valid_port(char *port)
{
	if (!ft_strisdigit(port))
		return (0);
	while (port[0] == '0')
		port++;
	if (ft_strlen(port) > 5 || ft_strlen(port) < 1)
		return (0);
	if (ft_atoi(port) > USHRT_MAX)
		return (0);
	return (1);
}

void		parse_port(t_env *env, char *port)
{
	if (!(valid_port(port)))
		ERROR("Invalid port");
	env->port = ft_atoi(port);
}
