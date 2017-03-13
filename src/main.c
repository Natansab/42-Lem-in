/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:08:33 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/13 15:53:57 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_init(t_room *room)
{
	room->name = NULL;
	room->links = NULL;
	room->coordx = 0;
	room->coordy = 0;
	room->status = 0;
	room->parent = 0;
	room->level = 0;
}

static void		ft_free_strarr(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static	void	main_inner(t_env e)
{
	if (!e.error && ft_find_path(e.room, e.nb_of_rooms))
	{
		ft_putstr(e.file);
		e.str = ft_pathtostr(e.room);
		ft_print_output(e.str, e.nb_of_ants);
		ft_free_strarr(e.str);
	}
	else
		ft_putstr_fd("ERROR\n", 2);
}

int				main(void)
{
	t_env	e;

	e.i = 0;
	e.count = 0;
	e.nb_of_rooms = 0;
	e.str = NULL;
	e.file = ft_stdtostr();
	while (e.file[e.i] && e.file[e.i++])
		if (e.file[e.i] == '\n')
			e.count++;
	if (!(e.room = malloc(sizeof(t_room) * e.count)))
		return (0);
	e.i = 0;
	while (e.i < e.count)
		ft_init(&(e.room[e.i++]));
	e.error = ft_read_std(&e.room, &e.nb_of_ants, &e.nb_of_rooms, e.file);
	main_inner(e);
	ft_free_room(e.room, e.count);
	free(e.room);
	free(e.file);
	return (0);
}
