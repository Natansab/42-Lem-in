/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:08:33 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/23 14:12:43 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		main()
{
	int		nb_of_ants;
	t_room	*room;
	int		nb_of_rooms;
	char	*file;
	int		i;

	i = 0;
	nb_of_rooms = 0;
	file = ft_stdtostr();
	while (file [i] && file[i++])
		if (file[i] == '\n')
			nb_of_rooms++;
	room = malloc(sizeof(t_room) * nb_of_rooms);
	nb_of_rooms = 0;
	ft_read_std(&room, &nb_of_ants, &nb_of_rooms, file);

	//  Debug section
	 printf("\n\nnb_of_ants is: %i\n", nb_of_ants);
	 dg_print_rooms(room, nb_of_rooms);
	 dg_print_links(room, nb_of_rooms);
	 ft_find_path(room, nb_of_rooms);
	return (0);
}
