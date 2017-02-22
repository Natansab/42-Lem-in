/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:27:28 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/22 15:27:38 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc(char **tab, char *neww)
{
	unsigned int	i;
	unsigned int	tab_size;
	char			**tab_tmp;

	tab_size = 0;
	while (tab[tab_size])
		tab_size++;
	if (!(tab_tmp = (char**)malloc(sizeof(char*) * (tab_size + 2))))
		return (NULL);
	i = 0;
	while (i < tab_size)
	{
		tab_tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	tab_tmp[i] = ft_strdup(neww);
	tab_tmp[i + 1] = 0;
	free(tab);
	free(neww);
	return (tab_tmp);
}
