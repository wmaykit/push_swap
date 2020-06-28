/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_value_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:59:28 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/05 23:00:34 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_max_value_stack(t_stack *st)
{
	int		index;
	int		max_value;
	t_lst	*iterator;

	max_value = 0;
	if (st && st->size)
	{
		if (st->size == 1)
			return (st->top->value);
		else
		{
			index = 1;
			max_value = st->top->value;
			iterator = st->top->next;
			while (index++ < st->size)
			{
				if (iterator->value > max_value)
					max_value = iterator->value;
				iterator = iterator->next;
			}
		}
	}
	return (max_value);
}
