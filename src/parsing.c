/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:48:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/25 11:16:25 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*ft_stdtostr()
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp1;
	char	*tmp2;
	int		ret;

	if (!(tmp1 = malloc(1)))
		return NULL;
	while ((ret = read(0, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp2 = ft_strdup(tmp1);
		free(tmp1);
		if (!(tmp1 = malloc(ft_strlen(tmp2) + BUFF_SIZE + 1)))
			return NULL;
		tmp1 = ft_strcpy(tmp1, tmp2);
		tmp1 = ft_strcat(tmp1, buf);
		free(tmp2);
	}
	return (tmp1);
}

char	*mini_gnl(int *ret, char *file)
{
	char *line;

	if (ft_strchr(file + *ret, '\n'))
		line = ft_strndup(file + *ret, ft_strchr(file + *ret, '\n') -
				(file + *ret));
	else
		line = ft_strdup(file + *ret);
	*ret += ft_strlen(line) + 1;
	return (line);
}

int		ft_read_std(t_room **room, int *nb_of_ants, int *nb_of_rooms, char *file)
{
	int		step;
	int		status;
	char	*line;
	int		ret;
	int		error;

	step = 0;
	status = 0;
	ret = 0;
	error = 0;
	line = NULL;
	while (ret < (int)ft_strlen(file))
	{
		line = mini_gnl(&ret, file);
		if (ft_strisdigit(line) && step == 0)
		{
			if ((*nb_of_ants = ft_atoi(line)) <= 0)
				break ;
			step = 1;
		}
		else if (step == 1 && !ft_strcmp(line, "##start"))
			status = 1;
		else if (step == 1 && !ft_strcmp(line, "##end"))
			status = 2;
		else if (line[0] == '#')
			;
		else if (ft_is_room(line) && step == 1)
		{
			ft_build_room(line, *room, &status, *nb_of_rooms);
			(*nb_of_rooms)++;
			if (ft_is_room_dup(*room, *nb_of_rooms))
				error = 1;
		}
		else if (ft_is_pipe(line, *room) && step >= 1)
		{
			ft_build_pipe(line, *room, *nb_of_rooms);
			step = 2;
		}
		else
			error = 2;
		free(line);
		line = NULL;
	}
	if (error)
	{
		ft_putstr("ERROR\n");
		if (line)
			free(line);
		return (1);
	}
	return (0);
}
