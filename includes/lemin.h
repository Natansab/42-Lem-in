/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:23:34 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/21 20:17:53 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_room{
	char	*name;
	t_list	*links;
	int		coordx;
	int		coordy;
	int		status;
	int		parent;
	int		level;
}				t_room;

typedef struct s_pipe{
	char	*room1;
	char	*room2;
	int		room1id;
	int		room2id;
}				t_pipe;

int		ft_is_pipe(char *line, t_room *room);
void	ft_build_pipe(char *line, t_room *room, int i);
int		ft_is_room(char *line);
void	ft_build_room(char *line, t_room *room, int *status, int i);
void	ft_find_path(t_room *room, int nb_of_rooms);
void	dg_print_links(t_room *room, int nb_of_rooms);

#endif
