/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:43:58 by nsabbah           #+#    #+#             */
/*   Updated: 2017/02/08 12:11:34 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int nb)
{
	if (nb < 0)
		nb = nb * -1;
	return (nb);
}
