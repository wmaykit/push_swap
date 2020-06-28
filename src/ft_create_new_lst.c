/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:16:21 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/17 15:05:23 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int			ft_create_new_lst(int value, t_stack *stack)
{
	t_lst	*new;

	if (!(new = ft_memalloc(sizeof(t_lst))))
		return (0);
	new->value = value;
	if (!stack->top)
		stack->top = new;
	else
	{
		new->next = stack->top;
		if (stack->top->next)
		{
			new->prev = stack->top->prev;
			stack->top->prev->next = new;
			stack->top->prev = new;
		}
		else
		{
			new->prev = stack->top;
			stack->top->next = new;
			stack->top->prev = new;
		}
		stack->top = new;
	}
	return (1);
}
