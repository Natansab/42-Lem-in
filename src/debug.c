/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:59:49 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/22 17:00:10 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	dg_print_rooms(t_room *room, int nb_of_rooms)
{
	int i;

	i = 0;
	printf("\n######## Print - Rooms ########\n\n");
	while (i < nb_of_rooms)
	{
		printf("%-10s | status: %i\n", room->name, room->status);
		room++;
		i++;
	}
}

void	dg_print_links(t_room *room, int nb_of_rooms)
{
	int		i;
	t_list *tmp;

	i = 0;
	printf("\n######## Print - links ########\n");

	while (i  < nb_of_rooms)
	{
		printf("\n");
		tmp = room[i].links;
		while (tmp)
		{
			// printf("i vaut %i :", i);
			printf("%s-%s\n",room[i].name, room[*(int*)(tmp->content)].name);
			tmp = tmp->next;
		}
		i++;
	}
}
