/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fbs_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:37:06 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/21 21:00:56 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_find_path_inner(t_room *room, int level, int curr_room)
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
			{
				;
			}
		}
	link = link->next;
	}
	// printf("room[*(int*)link->content].level : %i\n", room[*(int*)room[curr_room].links->content].level);
	// printf("room[*(int*)link->content].parent : %i\n", room[*(int*)room[curr_room].links->content].parent);
 }


void	ft_find_path(t_room *room, int nb_of_rooms)
{
	int		i;
	int		level;
	int		curr_room;
	i = 0;
	// initialisation
	while(i < nb_of_rooms)
	{
		room[i].parent = -1;
		room[i].level = -1;
		i++;
	}

	i = 0;
	// printf("%s-%s\n",room[0].name, room[*(int*)(room[0].links->content)].name);

	// on trouve la salle start
	while(i < nb_of_rooms && room[i].status != 1)
		i++;
	room[i].level = 0;
	level = 1;
	curr_room = i;
	ft_find_path_inner(room, level, curr_room);
}
