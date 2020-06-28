/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_sa_and_sb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:43:09 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/17 22:48:18 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	ft_rotate_sa_and_sb(t_stacks *stacks)
{
	ft_rotate_stack(&stacks->sa);
	ft_rotate_stack(&stacks->sb);
}
