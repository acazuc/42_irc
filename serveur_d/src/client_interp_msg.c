/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_interp_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:47:43 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 15:57:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		client_interp_msg(t_env *env, t_client *client)
{
	(void)env;
	(void)client;
	ft_putstr("new msg\n");
	return (1);
}
