/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:48:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/13 14:39:30 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*ft_stdtostr(void)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp1;
	char	*tmp2;
	int		ret;

	if (!(tmp1 = malloc(1)))
		return (NULL);
	*tmp1 = '\0';
	while ((ret = read(0, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp2 = ft_strdup(tmp1);
		free(tmp1);
		if (!(tmp1 = malloc(ft_strlen(tmp2) + BUFF_SIZE + 1)))
			return (NULL);
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

void	ft_init_env(t_env *e)
{
	(e->step) = 0;
	(e->status) = 0;
	(e->ret) = 0;
	(e->error) = 0;
}

void	ft_error(t_env e, t_room **room, int *nb_of_rooms, int *error)
{
	if (e.step != 3 || e.error || s_e(*room, *nb_of_rooms) ||
			room_dup(*room, *nb_of_rooms))
	{
		if (e.line)
			free(e.line);
		*error = 4;
	}
}

int		ft_read_std(t_room **room, int *nb_of_ants,
			int *nb_of_rooms, char *file)
{
	t_env	e;

	ft_init_env(&e);
	while (!(e.line = NULL) && e.ret < (int)ft_strlen(file))
	{
		e.line = mini_gnl(&e.ret, file);
		if (ft_strisdigit(e.line) && e.step == 0 &&
				(*nb_of_ants = ft_atoi(e.line)))
			e.step = 1;
		else if ((e.step == 1 || e.step == 2) && !ft_strcmp(e.line, "##start"))
			e.status = 1;
		else if ((e.step == 1 || e.step == 2) && !ft_strcmp(e.line, "##end"))
			e.status = 2;
		else if ((e.step == 1 || e.step == 2) && ft_is_room(e.line) &&
				(e.step = 2))
			ft_build_room(e.line, *room, &e.status, (*nb_of_rooms)++);
		else if (e.step >= 2 && ft_is_pipe(e.line, *room, *nb_of_rooms) &&
				(e.step = 3))
			ft_build_pipe(e.line, *room, *nb_of_rooms);
		else if (e.line[0] != '#')
			e.error = 2;
		free(e.line);
	}
	ft_error(e, room, nb_of_rooms, &e.error);
	return (e.error);
}
