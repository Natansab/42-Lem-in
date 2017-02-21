/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:19:18 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/21 18:40:02 by nsabbah          ###   ########.fr       */
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
