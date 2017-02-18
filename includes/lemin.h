/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:23:34 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/18 18:12:38 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_room{
	char	*name;
	int		nb_of_links;
	t_list	*links;
	int		coordx;
	int		coordy;
	int		end;
	int		start;
	int		parent;
	int		color;
}				t_room;

typedef struct s_pipe{
	char	*room1;
	char	*room2;
	int		room1id;
	int		room2id;
}				t_pipe;

#endif
