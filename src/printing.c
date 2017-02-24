/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:34:18 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/24 17:13:27 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		ft_nb_of_rooms(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_output(char **str, int nb_of_ants)
{
	int	ants_out;
	int first_ant;
	int rooms;
	// int i;
	// int j = 1;

	rooms = ft_nb_of_rooms(str);
	ants_out = 1;
	first_ant = 1;
	(void)str;
	(void)nb_of_ants;

	printf("\nrooms vaut %i\n", rooms);
	// while (nb < rooms)
	// 	;

	// while(first_ant <= nb_of_ants)
	// {
	// 	i = 0;
	// 	printf("\n");
	// 	while (i <= (rooms - 1) && i < ants_out)
	// 	{
	// 		printf("L%i-%s ", first_ant + i, str[j]);
	// 		i++;
	// 	}
	// 	ants_out++;
	// 	j++;
	// }

	int	i;
	int	j;

	i = 1;
	while (i < rooms)
	{
		j = 0;
		while (j < MIN(i, nb_of_ants))
		{
			ft_putstr("L");
			ft_putnbr(j + 1);
			ft_putstr("-");
			ft_putstr(str[i - j]);
			ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}

	i = 1;
	while (++i <= nb_of_ants - rooms)
	{
		j = -1;
		while (++j < rooms + 1)
		{
			ft_putstr("L");
			ft_putnbr(j + 1);
			ft_putstr("-");
			ft_putstr(str[i - j]);
			ft_putstr(" ");
		}
		ft_putstr("\n");
	}
}
