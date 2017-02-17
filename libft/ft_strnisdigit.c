/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnisdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:19:20 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/17 17:55:48 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ctype.h"

int	ft_strnisdigit(char *str, int n)
{
	int i;

	i = 0;
	if (!(*str))
		return (0);
	while (*str && i < n)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
		i++;
	}
	return (1);
}
