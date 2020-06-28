/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:42:57 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/11 13:29:02 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

t_boolean	ft_has_equal(int *i_sort_nbr, int i_size)
{
	int	index;

	index = 0;
	while (index < i_size)
	{
		if (i_sort_nbr[index] == i_sort_nbr[index + 1])
			return (TRUE);
		++index;
	}
	return (FALSE);
}
