/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:28:05 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/06 16:30:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		buffer_write_str(t_buffer *buffer, char *str)
{
	return (buffer_write(buffer, str, ft_strlen(str)));
}
