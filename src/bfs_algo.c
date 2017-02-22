/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fbs_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:37:06 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/22 14:36:01 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_print_smallest_path(t_room *room)
{
	int	i;
	int	j;
	int count;

	i = 0;
	count = 0;
	while (room[i].status != 2)
		i++;
	j = i;
	printf("Smallest path w/ room id\n");
	while (room[i].status != 1)
	{
		printf("%i>>", i);
		i = room[i].parent;
		count++;
	}
	printf("%i\n", i);

	printf("Smallest path w/ room name\n");
	while (room[j].status != 1)
	{
		printf("%s>>", room[j].name);
		j = room[j].parent;
	}
	printf("%s", room[j].name);
	printf("Length of the path:\n%i", count);
}

void	ft_find_path_inner(t_room *room, int level, int curr_room)
{
	t_list *link;

	printf("\n####### CURRENT ROOM IS: %i #######\n", curr_room);
	link = room[curr_room].links;
	while (link)
	{
		if (room[*(int*)link->content].level == -1)
		{
			room[*(int*)link->content].level = level;
			room[*(int*)link->content].parent = curr_room;
			// Printing section
			printf("\nId of changed room : %i\n", *(int*)link->content);
			printf("room[*(int*)link->content].level : %i\n", room[*(int*)link->content].level);
			printf("room[*(int*)link->content].parent : %i\n", room[*(int*)link->content].parent);
			if (room[*(int*)link->content].status == 2)
			{
				printf("Smallest path found: \n\n\n");
				ft_print_smallest_path(room);
				exit (0);
			}
		}
	link = link->next;
	}
}


void	ft_find_path(t_room *room, int nb_of_rooms)
{
	int		i;
	int		level;
	int		curr_room;
	int		j;
	int		bp;

	i = 0;
	while(i < nb_of_rooms)
	{
		room[i].parent = -1;
		room[i].level = -1;
		i++;
	}

	i = 0;

	while(i < nb_of_rooms && room[i].status != 1)
		i++;
	room[i].level = 0;
	level = 1;
	curr_room = i;
	ft_find_path_inner(room, level, curr_room);
	j = 1;
	i = 0;
	bp = 1;
	while (bp == 1)
	{
		i = 0;
		bp = 0;
		level++;
		while (i < nb_of_rooms)
		{
			if (room[i].level == level - 1)
			{
				ft_find_path_inner(room, level, i);
				bp = 1;
			}
			i++;
		}
	}
	printf("\n\n######### PAS DE SOLUTION #########\n\n");
}
