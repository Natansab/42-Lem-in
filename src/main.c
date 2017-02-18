/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:08:33 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/18 18:23:03 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int	ft_is_pipe(char *line)
{
	char	*dash;

	if (!(dash = ft_strchr(line, '-')) ||
			dash == line ||
				ft_strchr(dash + 1, '-')||
					!ft_strlen(dash + 1))
		return (0);
	return (1);
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

int		main()
{
	char	*line;
	int		nb_of_ants;
	t_room	*room;
	int		step;
	int		error;
	int		start;
	int		end;
	int		i;
	int		j;
	t_pipe	pipe;

	nb_of_ants = 0;
	step = 0;
	error = 0;
	start = 0;
	end = 0;
	i = 0;
	j = 0;

	// Find a way to know the number of room before doing anything
	room = malloc(sizeof(t_room) * 10);
	while (get_next_line(0, &line))
	{
		printf(">>>>>> %s\n", line);
		if (step == 0)
		{
			if (!ft_strisdigit(line))
				error++;
			nb_of_ants = ft_atoi(line);
			step = 1;
		}
		if (!ft_strcmp(line, "##start"))
			start = 1;
		if (!ft_strcmp(line, "##end"))
			end = 1;
		if (ft_is_room(line))
		{
			ft_bzero(&room[i], sizeof(t_room));
			// if (pipe != 0)
			// 	printf("ERROR\n");
			room[i].name = ft_strndup(line, ft_strchr(line, ' ') - line);
			room[i].start = start;
			room[i].end = end;
			start = 0;
			end = 0;
			// printf("	nom : %s| start : %i et end : %i ### \n", room[i].name, room[i].start, room[i].end);

			// Check if not duplicates in name or no 2 starts or 2 ends
			i++;
		}

		if (ft_is_pipe(line))
		{
			pipe.room1 = ft_strndup(line, ft_strchr(line, '-') - line);
			pipe.room2 = ft_strchr(line, '-') + 1;
			j = 0;
			while (j < i && ft_strcmp(room[j].name, pipe.room1))
				j++;
			pipe.room1id = j;
			j = 0;
			while (j < i && ft_strcmp(room[j].name, pipe.room2))
				j++;
			pipe.room2id = j;
			if (room[pipe.room1id].links)
				room[pipe.room1id].links = ft_lstnew(&(pipe.room2id), sizeof(int));
			else
				ft_lstadd(&room[pipe.room1id].links, ft_lstnew(&(pipe.room2id), sizeof(int)));
		}
			// Check if coherent with the rooms
			// Add pipe to the chained list

		free(line);
	}

	j = 0;
	while (j < i)
	{
		printf("room name is %s\n", room[j].name);
		while (room[j].links)
		{
			printf("link : %i\n", *(int*)(room[j].links->content));
			room[j].links = room[j].links->next;
		}
		j++;
	}
	printf("nb_of_ants is: %i\n", nb_of_ants);
	return (0);
}
