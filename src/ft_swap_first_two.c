/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_first_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:33:06 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/14 00:19:24 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	ft_swap_first_two(t_stack *stack)
{
	int	tmp;

	if (stack->top && stack->top->next)
	{
		tmp = stack->top->next->value;
		stack->top->next->value = stack->top->value;
		stack->top->value = tmp;
		tmp = stack->top->next->color;
		stack->top->next->color = stack->top->color;
		stack->top->color = tmp;
		tmp = stack->top->next->sweeps;
		stack->top->next->sweeps = stack->top->sweeps;
		stack->top->sweeps = tmp;
	}
}
