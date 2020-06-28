/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate_sa_and_sb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:43:09 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/17 22:52:46 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	ft_rrotate_sa_and_sb(t_stacks *stacks)
{
	ft_rrotate_stack(&stacks->sa);
	ft_rrotate_stack(&stacks->sb);
}
