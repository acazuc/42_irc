/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_interp_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:49:45 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 15:57:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		client_interp_cmd(t_env *env, t_client *client)
{
	(void)env;
	(void)client;
	ft_putstr("new cmd\n");
	return (1);
}
