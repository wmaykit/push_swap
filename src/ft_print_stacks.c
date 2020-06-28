/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:14:12 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 15:50:39 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	pr_print_entry_stacks(t_stacks *stacks, int size)
{
	t_lst	*ai;
	t_lst	*bi;

	ai = stacks->sa.top;
	bi = stacks->sb.top;
	while (size)
	{
		ft_printf("%8d    %8d  |size a = %d|size b = %d|\n",
				(ai ? ai->value : 0), (bi ? bi->value : 0), stacks->sa.size,
															stacks->sb.size);
		if (bi)
			bi = bi->next;
		if (ai)
			ai = ai->next;
		if (ai == stacks->sa.top)
			ai = NULL;
		if (bi == stacks->sb.top)
			bi = NULL;
		--size;
	}
}

void		ft_print_stacks(t_stacks *stacks)
{
	int		len;

	len = 0;
	if (stacks->sa.top)
		len = stacks->sa.size;
	if (stacks->sb.top)
		if (stacks->sb.size > len)
			len = stacks->sb.size;
	pr_print_entry_stacks(stacks, len);
	ft_printf("%8s    %8s\n", "--------", "--------");
	ft_printf("%4c    %8c\n", 'a', 'b');
}
