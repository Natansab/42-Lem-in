/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:34:18 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/13 16:38:31 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	ft_print_in(char **str, int rooms, int nb_of_ants)
{
	int i;
	int j;

	i = 1;
	ft_putstr("\n");
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
}

static void	ft_print_btw(char **str, int rooms, int nb_of_ants)
{
	int i;
	int j;

	i = 1;
	while (++i < nb_of_ants - (rooms - 3))
	{
		j = 0;
		while (j < rooms - 1)
		{
			ft_putstr("L");
			ft_putnbr(j + i);
			ft_putstr("-");
			ft_putstr(str[rooms - 1 - j]);
			ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
	}
}

static void	ft_print_end(char **str, int rooms, int nb_of_ants)
{
	int i;
	int j;

	i = 0;
	while (++i <= MIN(rooms - 2, nb_of_ants))
	{
		j = 0;
		while (++j + i < MIN(rooms - 1, nb_of_ants) + 1)
		{
			ft_putstr("L");
			ft_putnbr(MAX(nb_of_ants - rooms + 1, 0) + j + i);
			ft_putstr("-");
			ft_putstr(str[rooms - j]);
			ft_putstr(" ");
		}
		if (j > 1)
			ft_putstr("\n");
	}
}

void		ft_print_output(char **str, int nb_of_ants)
{
	int rooms;

	rooms = 0;
	while (str[rooms])
		rooms++;
	ft_print_in(str, rooms, nb_of_ants);
	if (nb_of_ants - (rooms - 2) - 1 > 0)
		ft_print_btw(str, rooms, nb_of_ants);
	ft_print_end(str, rooms, nb_of_ants);
}
