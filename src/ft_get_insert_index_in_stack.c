/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_insert_index_in_stack.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 22:14:14 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 15:33:11 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_get_insert_index_in_stack(t_stack *st, int insert_num)
{
	t_lst	*iterator;
	int		index;

	index = 0;
	if (st->size)
	{
		if (insert_num > st->max_value || insert_num < st->min_value)
			return (ft_get_index_value_in_stack(st, st->min_value));
		iterator = st->top;
		while (index < st->size)
		{
			if (insert_num > iterator->prev->value &&
												insert_num < iterator->value)
				return (index);
			iterator = iterator->next;
			++index;
		}
		return (0);
	}
	return (0);
}
