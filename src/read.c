/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:48:24 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/22 18:08:21 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*ft_stdtostr()
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp1;
	char	*tmp2;
	int		ret;

	tmp1 = malloc(1);
	while ((ret = read(0, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp2 = malloc(ft_strlen(tmp1) + BUFF_SIZE + 1);
		tmp2 = ft_strcpy(tmp2, tmp1);
		tmp2 = ft_strcat(tmp2, buf);
		tmp1 = tmp2;
		free(tmp2);
	}
	printf("%s\n", tmp1);
	free(tmp1);
	return (NULL);
}

void	ft_read_std(t_room **room, int *nb_of_ants, int *nb_of_rooms)
{
	int		step;
	int		status;
	char	*line;

	step = 0;
	status = 0;

	 while (get_next_line(0, &line))
	 {
	 	if (ft_strisdigit(line) && step == 0)
	 	{
	 		*nb_of_ants = ft_atoi(line);
	 		if (*nb_of_ants <= 0)
	 		{
	 			free(line);
	 			return ;
	 		}
	 	step = 1;
	 	}

	 	status = (!ft_strcmp(line, "##start")) ? 1 : status;
	 	status = (!ft_strcmp(line, "##end")) ? 2 : status;

	 	if (ft_is_room(line) && step == 1)
	 	{
	 		ft_build_room(line, *room, &status, *nb_of_rooms);
	 		(*nb_of_rooms)++;
	 	}
	 	if (ft_is_pipe(line, *room))
	 	{
	 		ft_build_pipe(line, *room, *nb_of_rooms);
	 		step = 2;
	 	}
	 	free(line);
	 }
}
