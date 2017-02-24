/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:23:34 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/24 17:08:03 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define BUFF_SIZE 1000

#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define MIN(x,y) (x <= y ? x : y)
#define MAX(x,y) (x <= y ? y : x)

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
int		ft_find_path(t_room *room, int nb_of_rooms);
void	dg_print_links(t_room *room, int nb_of_rooms);
void	dg_print_rooms(t_room *room, int nb_of_rooms);
int		ft_read_std(t_room **room, int *nb_of_ants, int *nb_of_rooms, char *file);
char	*ft_stdtostr();
int		ft_is_room_dup(t_room *room, int nb_of_rooms);
void	ft_free_room(t_room *room, int nb_of_rooms);
char	**ft_pathtostr(t_room *room);
void	ft_print_output(char **str, int nb_of_ants);
#endif
