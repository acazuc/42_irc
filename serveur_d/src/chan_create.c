/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chan_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 19:54:03 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 20:19:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

t_chan	*chan_create(t_env *env, char *name)
{
	t_chan_list	*new;

	if (!(new = malloc(sizeof(*new))))
		ERROR("malloc failed");
	ft_memset(new, 0, sizeof(*new));
	if (!(new->chan = malloc(sizeof(*new->chan))))
		ERROR("malloc failed");
	ft_memset(new->chan, 0, sizeof(*new->chan));
	ft_strcpy(new->chan->name, name);
	new->next = env->chans;
	env->chans = new;
	return (new->chan);
}
