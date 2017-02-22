/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:08:33 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/22 15:01:06 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <unistd.h>

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

int		main()
{
	char	*line;
	int		nb_of_ants;
	t_room	*room;
	int		step;
	int		error;
	int		status;
	int		nb_of_rooms;

	step = 0;
	error = 0;
	status = 0;
	nb_of_rooms = 0;


	room = malloc(sizeof(t_room) * 1500);
	while (get_next_line(0, &line))
	{
		if (ft_strisdigit(line) && step == 0)
		{
			nb_of_ants = ft_atoi(line);
			if (nb_of_ants <= 0)
			{
				free(line);
				return (0);
			}
		step = 1;
		}

		status = (!ft_strcmp(line, "##start")) ? 1 : status;
		status = (!ft_strcmp(line, "##end")) ? 2 : status;

		if (ft_is_room(line) && step == 1)
		{
			ft_build_room(line, room, &status, nb_of_rooms);
			nb_of_rooms++;
		}
		if (ft_is_pipe(line, room))
		{
			ft_build_pipe(line, room, nb_of_rooms);
			step = 2;
		}
		free(line);
	}
	printf("%s-%s\n",room[0].name, room[*(int*)(room[0].links->content)].name);

 // 	Debug section
	printf("\n\nnb_of_ants is: %i\n", nb_of_ants);
	dg_print_rooms(room, nb_of_rooms);
	dg_print_links(room, nb_of_rooms);
	// printf("%s-%s\n",room[0].name, room[*(int*)(room[0].links->content)].name);

	ft_find_path(room, nb_of_rooms);

	return (0);
}
