/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:01:39 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/14 22:08:30 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	ft_execute_union_command(t_push_swap *push_swap, t_command *com)
{
	while (com->rotate-- > 0)
		pr_rr_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
	while (com->rrotate-- > 0)
		pr_rrr_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
}

static void	ft_execute_command_sa(t_push_swap *push_swap, t_command *com)
{
	while (com->rotate-- > 0)
		pr_ra_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
	while (com->rrotate-- > 0)
		pr_rra_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
}

static void	ft_execute_command_sb(t_push_swap *push_swap, t_command *com)
{
	while (com->rotate-- > 0)
		pr_rb_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
	while (com->rrotate-- > 0)
		pr_rrb_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
}

void		ft_execute_commands(t_push_swap *push_swap, t_command *union_com,
											t_command *com1, t_command *com2)
{
	ft_execute_union_command(push_swap, union_com);
	ft_execute_command_sa(push_swap, com1);
	ft_execute_command_sb(push_swap, com2);
}
