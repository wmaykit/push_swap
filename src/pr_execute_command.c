/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_execute_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:01:29 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 17:04:57 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	pr_execute(t_push_swap *ps,
							int *num_cmds,
							void (**cmds)(t_stacks*, t_buff*))
{
	while (num_cmds[0]-- > 0)
		cmds[0](&ps->stacks, &ps->buff);
	while (num_cmds[1]-- > 0)
		cmds[1](&ps->stacks, &ps->buff);
	while (num_cmds[2]-- > 0)
		cmds[2](&ps->stacks, &ps->buff);
}

static void	pr_put_param(int *m_arry, void (**cmds_f)(t_stacks*, t_buff*),
														t_commands *cmds, int k)
{
	if (k == 1)
	{
		m_arry[0] = cmds->c_union.rotate;
		m_arry[1] = cmds->select_val.rotate;
		m_arry[2] = cmds->insert_place.rotate;
		cmds_f[0] = pr_rr_and_add_to_buff;
		cmds_f[1] = pr_rb_and_add_to_buff;
		cmds_f[2] = pr_ra_and_add_to_buff;
	}
	else if (k == 2)
	{
		m_arry[0] = cmds->c_union.rrotate;
		m_arry[1] = cmds->select_val.rrotate;
		m_arry[2] = cmds->insert_place.rrotate;
		cmds_f[0] = pr_rrr_and_add_to_buff;
		cmds_f[1] = pr_rrb_and_add_to_buff;
		cmds_f[2] = pr_rra_and_add_to_buff;
	}
}

void		pr_execute_command(t_commands cmds, t_push_swap *ps, char insert_st)
{
	int		num_cmds[3];
	void	(*cmds_f[3])(t_stacks*, t_buff*);

	if (insert_st == 'a' || insert_st == 'A')
	{
		pr_put_param(num_cmds, cmds_f, &cmds, 1);
		pr_execute(ps, num_cmds, cmds_f);
		pr_put_param(num_cmds, cmds_f, &cmds, 2);
		pr_execute(ps, num_cmds, cmds_f);
	}
}
