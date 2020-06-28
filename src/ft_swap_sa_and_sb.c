/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_sa_and_sb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:49:46 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/17 21:59:42 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	ft_swap_sa_and_sb(t_stacks *stacks)
{
	ft_swap_first_two(&stacks->sa);
	ft_swap_first_two(&stacks->sb);
}
