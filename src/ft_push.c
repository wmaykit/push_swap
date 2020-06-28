/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 09:42:52 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 15:53:41 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	ft_add_to_empty_stack(t_stack *from, t_stack *here)
{
	here->top = ft_cut_top_node(from);
	here->top->next = NULL;
	here->top->prev = NULL;
}

static void	ft_add_to_non_empty_stack(t_stack *from, t_stack *here)
{
	t_lst	*cut_node;

	cut_node = ft_cut_top_node(from);
	if (here->top->next)
	{
		cut_node->next = here->top;
		cut_node->prev = here->top->prev;
		here->top->prev->next = cut_node;
		here->top->prev = cut_node;
		here->top = cut_node;
	}
	else
	{
		here->top->next = cut_node;
		here->top->prev = cut_node;
		cut_node->next = here->top;
		cut_node->prev = here->top;
		here->top = cut_node;
	}
}

void		ft_push(t_stack *from, t_stack *here)
{
	if (from->top)
	{
		if (!here->size)
		{
			here->max_value = from->top->value;
			here->min_value = from->top->value;
		}
		else if (from->top->value > here->max_value)
			here->max_value = from->top->value;
		else if (from->top->value < here->min_value)
			here->min_value = from->top->value;
		if (here->top)
			ft_add_to_non_empty_stack(from, here);
		else
			ft_add_to_empty_stack(from, here);
		++here->size;
	}
}
