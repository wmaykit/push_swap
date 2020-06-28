/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sort_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:18:36 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 15:39:07 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	pr_fill_arry(t_stack *stack, int *arry)
{
	t_lst	*iterator;

	iterator = NULL;
	if (stack->top)
	{
		*arry++ = stack->top->value;
		iterator = stack->top->next;
	}
	while (iterator && iterator != stack->top)
	{
		*arry++ = iterator->value;
		iterator = iterator->next;
	}
}

int			*ft_get_sort_nbr(t_stack *i_stack)
{
	int		*sort_nbr;

	if (!(sort_nbr = ft_memalloc(i_stack->size * sizeof(int))))
		return (NULL);
	pr_fill_arry(i_stack, sort_nbr);
	ft_quick_sort(sort_nbr, i_stack->size - 1);
	return (sort_nbr);
}
