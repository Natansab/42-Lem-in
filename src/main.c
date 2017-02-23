/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:08:33 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/23 17:54:44 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_init(t_room room)
{
	room.name = NULL;
	room.links = NULL;
	room.status = 0;
	room.parent = 0;
	room.level = 0;
}

int		main()
{
	int		nb_of_ants;
	t_room	*room;
	int		nb_of_rooms;
	int		count;
	char	*file;
	int		i;
	int		error;

	i = 0;
	count = 0;
	file = ft_stdtostr();
	while (file [i] && file[i++])
		if (file[i] == '\n')
			count++;
	room = malloc(sizeof(t_room) * count);
	i = 0;
	while (i < count)
		ft_init(room[i++]);
	nb_of_rooms = 0;
	error = ft_read_std(&room, &nb_of_ants, &nb_of_rooms, file);
	if (!error)
	{
		ft_putstr(file);
		ft_find_path(room, nb_of_rooms);
	}
	ft_free_room(room, count);
	free(room);
	free(file);
	while (1)
		;
	return (0);
}
