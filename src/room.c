/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:19:18 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/23 17:51:35 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_build_room(char *line, t_room *room, int *status, int i)
{
	ft_bzero(&room[i], sizeof(t_room));
	room[i].name = ft_strndup(line, ft_strchr(line, ' ') - line);
	room[i].status = *status;
	*status = 0;
}

int		ft_is_room(char *line)
{
	char	*space1;
	char	*space2;

	if (ft_strchr("L#", *line) ||
		!(space1 = ft_strchr(line, ' ')) ||
			!(space2 = ft_strchr(space1 + 1, ' ')) ||
				!(ft_strnisdigit(space1 + 1, space2 - (space1 + 1))) ||
					!ft_strisdigit(space2 + 1))
		return (0);
	return (1);
}

int		ft_is_room_dup(t_room *room, int nb_of_rooms)
{
	char	*last_room;
	int		i;

	i = 0;
	last_room = room[nb_of_rooms - 1].name;
	while (i < nb_of_rooms - 1)
	{
		if (!ft_strcmp(room[i].name, last_room))
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_room(t_room *room, int nb_of_rooms)
{
	int i;
	t_list *tmp;

	i = 0;
	while (i < nb_of_rooms)
	{
		if (room[i].name)
		{
			if (*(room[i].name))
				free(room[i].name);
			room[i].name = NULL;
		}
		while (room[i].links)
		{
			if (room[i].links->next)
				tmp = room[i].links->next;
			free(room[i].links->content);
			free(room[i].links);
			room[i].links = room[i].links->next;
		}
		i++;
	}
}
