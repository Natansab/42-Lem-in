/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:19:18 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/13 13:54:02 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_build_pipe(char *line, t_room *room, int i)
{
	int		j;
	t_pipe	pipe;

	pipe.room1 = ft_strndup(line, ft_strchr(line, '-') - line);
	pipe.room2 = ft_strchr(line, '-') + 1;
	j = 0;
	while (j < i && ft_strcmp(room[j].name, pipe.room1))
		j++;
	free(pipe.room1);
	pipe.room1id = j;
	j = 0;
	while (j < i && ft_strcmp(room[j].name, pipe.room2))
		j++;
	pipe.room2id = j;
	if (!room[pipe.room1id].links)
		room[pipe.room1id].links = ft_lstnew(&(pipe.room2id), 4);
	else
		ft_lstadd(&room[pipe.room1id].links, ft_lstnew(&(pipe.room2id), 4));
	if (!room[pipe.room2id].links)
		room[pipe.room2id].links = ft_lstnew(&(pipe.room1id), 4);
	else
		ft_lstadd(&room[pipe.room2id].links, ft_lstnew(&(pipe.room1id), 4));
}

int		ft_is_pipe(char *line, t_room *room, int nb_of_rooms)
{
	char	*dash;
	t_pipe	pipe;
	int		i;

	if (!(dash = ft_strchr(line, '-')) || dash == line ||
			ft_strchr(dash + 1, '-') || !ft_strlen(dash + 1))
		return (0);
	pipe.room1 = ft_strndup(line, ft_strchr(line, '-') - line);
	pipe.room2 = ft_strchr(line, '-') + 1;
	i = 0;
	while (i < nb_of_rooms && room && room->name)
	{
		i = (pipe.room1 && pipe.room2 && *(pipe.room1) && *(pipe.room2) &&
				(!ft_strcmp(pipe.room1, room->name) ||
					!ft_strcmp(pipe.room2, room->name))) ? i + 1 : i;
		room++;
	}
	if (i < 2 || pipe.room1 == pipe.room2)
	{
		free(pipe.room1);
		return (0);
	}
	free(pipe.room1);
	return (1);
}
