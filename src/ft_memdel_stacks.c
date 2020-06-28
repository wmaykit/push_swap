/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:57:02 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 15:37:56 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	ft_memdel_stack(t_lst *current, int size)
{
	if (current && size > 1)
		ft_memdel_stack(current->next, size - 1);
	current->next = NULL;
	current->prev = NULL;
	free(current);
	current = NULL;
}

int			ft_memdel_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		if (stacks->sa.size)
			ft_memdel_stack(stacks->sa.top, stacks->sa.size);
		if (stacks->sb.size)
			ft_memdel_stack(stacks->sb.top, stacks->sb.size);
	}
	return (0);
}
