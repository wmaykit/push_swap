/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:36:03 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/11 13:28:18 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

t_boolean		ft_check_sort(t_stacks *stacks)
{
	int		len;
	t_lst	*current;

	if (stacks->sb.size > 0)
		return (FALSE);
	if (stacks->sa.top)
	{
		len = stacks->sa.size;
		current = stacks->sa.top;
		while (--len)
		{
			if (current->value > current->next->value)
				return (FALSE);
			current = current->next;
		}
	}
	return (TRUE);
}
