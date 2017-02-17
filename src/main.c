/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:08:33 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/17 19:29:34 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_is_pipe(char *line)
{
	t_pipe	pipe;
	char	*dash;

	if ()
}

void	ft_is_room(char *line, int *start, int *end)
{
	char	*space1;
	char	*space2;
	t_room	room;

	if (ft_strchr("L#", *line) ||
		!(space1 = ft_strchr(line, ' ')) ||
			!(space2 = ft_strchr(space1 + 1, ' ')) ||
				!(ft_strnisdigit(space1 + 1, space2 - (space1 + 1))) ||
					!ft_strisdigit(space2 + 1))
		return ;
	room.name = ft_strndup(line, space1 - line);
	room.coordx = ft_atoi(space1 + 1);
	room.coordy = ft_atoi(space2 + 1);
	room.start = *start;
	room.end = *end;
	*start = 0;
	*end = 0;
	printf("%s %i %i start : %i et end : %i ### \n", room.name, room.coordx, room.coordy, room.start, room.end);
}

int		main()
{
	char	*line;
	int		nb_of_ants;
	int		step;
	int		error;
	int		start;
	int		end;

	nb_of_ants = 0;
	step = 0;
	error = 0;
	start = 0;
	end = 0;
	while (get_next_line(0, &line))
	{
		printf("%s\n", line);
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
		if ((room =ft_is_room(line, &start, &end))
			// Add room to the chained list
			// Check if everything is ok (no duplicates)
		if ((pipe = ft_is_pipe(line)))
			// Check if coherent with the rooms
			// Add pipe to the chained list
		ft_is_pipe(line);

		// free(line);
	}
	printf("nb_of_ants is: %i\n", nb_of_ants);
	return (0);
}
