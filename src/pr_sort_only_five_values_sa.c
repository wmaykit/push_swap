/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_sort_only_five_values_sa.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 22:30:16 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 17:20:27 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	pr_normalize_stack(t_push_swap *ps)
{
	int		cmd;

	cmd = ft_get_index_value_in_stack(&ps->stacks.sa, ps->stacks.sa.min_value);
	if (cmd > ps->stacks.sa.size / 2)
	{
		cmd = ps->stacks.sa.size - cmd;
		while (cmd--)
			pr_rra_and_add_to_buff(&ps->stacks, &ps->buff);
	}
	else
		while (cmd--)
			pr_ra_and_add_to_buff(&ps->stacks, &ps->buff);
}

void		pr_sort_only_five_values_sa(t_push_swap *ps)
{
	t_commands	low_num_cmd;

	if (ps->stacks.sa.size <= 5)
	{
		pr_pb_and_add_to_buff(&ps->stacks, &ps->buff);
		pr_pb_and_add_to_buff(&ps->stacks, &ps->buff);
		ps->stacks.sa.max_value = ft_max_value_stack(&ps->stacks.sa);
		ps->stacks.sa.min_value = ft_min_value_stack(&ps->stacks.sa);
		pr_sort_only_three_values_sa(&ps->stacks, &ps->buff);
		while (ps->stacks.sb.size)
		{
			low_num_cmd = ft_get_low_num_cmd(&ps->stacks.sa, &ps->stacks.sb);
			pr_execute_command(low_num_cmd, ps, 'A');
			pr_pa_and_add_to_buff(&ps->stacks, &ps->buff);
			ps->stacks.sb.max_value = ft_max_value_stack(&ps->stacks.sb);
			ps->stacks.sb.min_value = ft_min_value_stack(&ps->stacks.sb);
		}
		pr_normalize_stack(ps);
	}
}
