/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_pb_and_add_to_buff.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:12:01 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/04 11:01:21 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	pr_pb_and_add_to_buff(t_stacks *stacks, t_buff *buff)
{
	ft_push_sb(stacks);
	pr_add_command_to_buff(buff, PB);
}
