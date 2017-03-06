/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:19:18 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/06 14:17:14 by nsabbah          ###   ########.fr       */
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

int		room_dup(t_room *room, int nb_of_rooms)
{
	int		i;
	int		j;

	j = 1;
	while (j < nb_of_rooms)
	{
		i = 0;
		while (i < j && room[i].name && room[j].name)
		{
			if (!ft_strcmp(room[i].name, room[j].name))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int		s_e(t_room *room, int nb_of_rooms)
{
	int		start;
	int		end;
	int		i;

	i = 0;
	start = 0;
	end = 0;
	while (i < nb_of_rooms)
	{
		start = (room[i].status == 1) ? start + 1 : start;
		end = (room[i].status == 2) ? end + 1 : end;
		i++;
	}
	if (start != 1 || end != 1)
		return (1);
	return (0);
}

void	ft_free_room(t_room *room, int nb_of_rooms_malloced)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < nb_of_rooms_malloced)
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
