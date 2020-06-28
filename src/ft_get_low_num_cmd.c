/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_low_num_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:59:05 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 15:32:11 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static t_commands	ft_get_commands(t_stack *h, t_stack *f, int curr_val)
{
	t_command		val;
	t_command		ins;
	t_commands		cmds;

	ft_bzero(&cmds, sizeof(t_commands));
	val = ft_get_num_lift_up_cmd(f, ft_get_index_value_in_stack(f, curr_val));
	ins = ft_get_num_lift_up_cmd(h, ft_get_insert_index_in_stack(h, curr_val));
	cmds.select_val = val;
	cmds.insert_place = ins;
	return (ft_get_best_commands(cmds));
}

t_commands			ft_get_low_num_cmd(t_stack *here, t_stack *from)
{
	t_commands		low_num_cmd;
	t_commands		curr_val_cmd;
	t_lst			*iterator;
	int				index;

	ft_bzero(&low_num_cmd, sizeof(t_commands));
	if (from->size)
	{
		index = 1;
		iterator = from->top;
		low_num_cmd = ft_get_commands(here, from, iterator->value);
		while (index++ < from->size)
		{
			iterator = iterator->next;
			curr_val_cmd = ft_get_commands(here, from, iterator->value);
			if (curr_val_cmd.num_all_cmd < low_num_cmd.num_all_cmd)
				low_num_cmd = curr_val_cmd;
		}
	}
	return (low_num_cmd);
}
