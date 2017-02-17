/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:23:34 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/17 19:03:06 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_room{
	char	*name;
	int		coordx;
	int		coordy;
	int		end;
	int		start;
}				t_room;

typedef struct s_pipe{
	int		room1;
	int		room2;
}				t_pipe;

#endif
