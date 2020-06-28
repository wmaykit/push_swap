/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:16:32 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/18 18:19:44 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	ft_rrotate_stack(t_stack *stack)
{
	if (stack->top && stack->top->prev)
		stack->top = stack->top->prev;
}
