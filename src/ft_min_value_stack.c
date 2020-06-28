/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_value_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:59:28 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/04 13:15:01 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_min_value_stack(t_stack *st)
{
	int		index;
	int		min_value;
	t_lst	*iterator;

	min_value = 0;
	if (st && st->size)
	{
		if (st->size == 1)
			return (st->top->value);
		else
		{
			index = 1;
			min_value = st->top->value;
			iterator = st->top->next;
			while (index++ < st->size)
			{
				if (iterator->value < min_value)
					min_value = iterator->value;
				iterator = iterator->next;
			}
		}
	}
	return (min_value);
}
