/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_value_in_stack.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:13:40 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/29 20:34:12 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_get_index_value_in_stack(t_stack *st, int value)
{
	t_lst	*current;
	int		index;

	index = 0;
	if (st && st->top && st->top->next)
	{
		if (st->top->value == value)
			return (0);
		current = st->top->next;
		while (current != st->top)
		{
			++index;
			if (current->value == value)
				return (index);
			current = current->next;
		}
	}
	return (index);
}
