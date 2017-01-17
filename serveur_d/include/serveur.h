/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:40:04 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/17 17:00:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# define BUF_SIZE 64000

# include "../../libft/include/libft.h"
# include <netinet/tcp.h>
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

# define ERROR(x) (error_quit(x, __FILE__, __LINE__))

typedef struct s_env			t_env;
typedef struct s_client			t_client;
typedef struct s_client_list	t_client_list;
typedef struct s_chan			t_chan;
typedef struct s_chan_list		t_chan_list;
typedef struct s_buffer			t_buffer;

void	parse_port(t_env *env, char *port);
void	server_listen(t_env *env);
void	server_accept(t_env *env);
void	server_select(t_env *env);
void	server_tick(t_env *env);
int		buffer_write(t_buffer *buffer, void *data, size_t len);
int		buffer_read(t_buffer *buffer, void *data, size_t len);
int		buffer_write_str(t_buffer *buffer, char *str);
void	buffer_flip(t_buffer *buffer);
void	buffer_clear(t_buffer *buffer);
int		client_write(t_client *client);
int		client_read(t_client *client);
void	client_add(t_env *env, int fd);
void	client_remove(t_env *env, t_client *client);
int		client_tick(t_env *env, t_client *client);
int		client_interp(t_env *env, t_client *client);
int		client_interp_cmd(t_env *env, t_client *client, char *cmd);
int		client_interp_msg(t_env *env, t_client *client, char *msg);
int		chan_send_msg(t_chan *chan, char *author, char *msg);
void	chan_remove_client(t_env *env, t_chan *chan, t_client *client);
void	chan_add_client(t_chan *chan, t_client *client);
void	error_quit(char *e, char *f, int l);
int		cmd_join(t_env *env, t_client *client, char **data);
int		cmd_leave(t_env *env, t_client *client, char **data);
int		cmd_who(t_env *env, t_client *client, char **data);
int		cmd_nick(t_env *env, t_client *client, char **data);
int		cmd_msg(t_env *env, t_client *client, char **data);
t_chan	*chan_create(t_env *env, char *name);

struct				s_buffer
{
	char			data[BUF_SIZE];
	size_t			pos;
	size_t			lim;
	size_t			cap;
};

struct				s_client
{
	int				fd;
	t_buffer		buf_r;
	t_buffer		buf_w;
	t_chan_list		*chans;
	t_chan			*chan;
	char			name[10];
};

struct				s_client_list
{
	t_client		*client;
	t_client_list	*next;
};

struct				s_chan
{
	char			name[10];
	t_client_list	*clients;
};

struct				s_chan_list
{
	t_chan			*chan;
	t_chan_list		*next;
};

struct				s_env
{
	t_client_list	*clients;
	t_chan_list		*chans;
	fd_set			sets[3];
	int				max_fd;
	uint16_t		port;
	int				fd;
};

#endif
