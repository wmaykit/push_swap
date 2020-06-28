/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_top_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:49:58 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/21 11:51:13 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

t_lst	*ft_cut_top_node(t_stack *from)
{
	t_lst *cut_node;

	cut_node = from->top;
	if (from->size > 0)
	{
		--from->size;
		if (from->top->next)
		{
			if (from->top->next == from->top->prev)
			{
				from->top->next->prev = NULL;
				from->top->next->next = NULL;
				from->top = from->top->next;
			}
			else
			{
				from->top->next->prev = from->top->prev;
				from->top->prev->next = from->top->next;
				from->top = from->top->next;
			}
		}
		else
			from->top = NULL;
	}
	return (cut_node);
}
