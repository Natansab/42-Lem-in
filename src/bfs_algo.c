/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:37:06 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/25 12:35:22 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	**ft_pathtostr(t_room *room)
{
	int		i;
	int		j;
	char	**str;


	i = 0;
	while (room[i].status != 2)
		i++;
	j = i;
	i = room[i].level;
	str = (char**)malloc(sizeof(char*) * (i + 2));
	str[i + 1] = NULL;
	while (i >= 0)
	{
		str[i] = ft_strdup(room[j].name);
		j = room[j].parent;
		i--;
	}
	return (str);
}

int		ft_find_path_inner(t_room *room, int level, int curr_room)
{
	t_list *link;

	link = room[curr_room].links;
	while (link)
	{
		if (room[*(int*)link->content].level == -1)
		{
			room[*(int*)link->content].level = level;
			room[*(int*)link->content].parent = curr_room;
			if (room[*(int*)link->content].status == 2)
				return (1);
		}
	link = link->next;
	}
	return (0);
}


int		ft_find_path(t_room *room, int nb_of_rooms)
{
	t_env	e;

	e.i = -1;
	while(++e.i < nb_of_rooms)
	{
		room[e.i].parent = -1;
		room[e.i].level = -1;
	}
	e.i = 0;
	while(e.i < nb_of_rooms && room[e.i].status != 1)
		e.i++;
	room[e.i].level = 0;
	e.level = 1;
	e.curr_room = e.i;
	ft_find_path_inner(room, e.level, e.curr_room);
	e.j = 1;
	e.i = 0;
	e.bp = 1;
	while (e.bp == 1 && !(e.bp = 0) && (e.i = -1) && (e.level++))
		while (++e.i < nb_of_rooms)
			if (room[e.i].level == e.level - 1)
				if ((e.bp = 1) && ft_find_path_inner(room, e.level, e.i))
					return (1);
	return (0);
}
