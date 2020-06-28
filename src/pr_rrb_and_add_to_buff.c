/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_rrb_and_add_to_buff.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:12:01 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/06 18:01:26 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	pr_rrb_and_add_to_buff(t_stacks *stacks, t_buff *buff)
{
	ft_rrotate_sb(stacks);
	pr_add_command_to_buff(buff, RRB);
}
