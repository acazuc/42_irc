/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 21:35:14 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/17 14:45:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../../libft/include/libft.h"
# include <netinet/tcp.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <sys/select.h>
# include <unistd.h>
# include <netdb.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>

# define BUF_SIZE 4096

# define ERROR(x) (error_quit(x, __FILE__, __LINE__))

typedef struct s_env	t_env;
typedef struct s_buffer	t_buffer;

void	do_connect(t_env *env, char *host, char *port);
void	looping(t_env *env);
void	error_quit(char *e, char *f, int l);
void	read_stdin(t_env *env);
void	check_connect(t_env *env);
void	send_socket(t_env *env);
void	read_socket(t_env *env);

struct			s_buffer
{
	char		data[BUF_SIZE];
	size_t		pos;
	size_t		lim;
	size_t		cap;
};

struct			s_env
{
	int			fd;
	int			connected;
	fd_set		sets[3];
	int			maxfd;
	t_buffer	buf_write;
	t_buffer	buf_stdin;
	t_buffer	buf_read;
};

#endif
