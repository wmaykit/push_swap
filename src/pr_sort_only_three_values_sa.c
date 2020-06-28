/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_sort_only_three_values_sa.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:23:45 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 17:19:55 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	pr_sort_sa_if_top_max_value(t_stacks *sts, t_buff *buff)
{
	if (sts->sa.top->next->value == sts->sa.min_value)
	{
		pr_ra_and_add_to_buff(sts, buff);
	}
	else
	{
		pr_sa_and_add_to_buff(sts, buff);
		pr_rra_and_add_to_buff(sts, buff);
	}
}

static void	pr_sort_sa_if_top_min_value(t_stacks *sts, t_buff *buff)
{
	if (sts->sa.top->next->value == sts->sa.max_value)
	{
		pr_sa_and_add_to_buff(sts, buff);
		pr_ra_and_add_to_buff(sts, buff);
	}
}

static void	pr_sort_sa_if_top_mid_value(t_stacks *sts, t_buff *buff)
{
	if (sts->sa.top->next->value == sts->sa.max_value)
		pr_rra_and_add_to_buff(sts, buff);
	else if (sts->sa.top->next->value == sts->sa.min_value)
		pr_sa_and_add_to_buff(sts, buff);
}

void		pr_sort_only_three_values_sa(t_stacks *sts, t_buff *buff)
{
	if (sts && sts->sa.size == 3)
	{
		if (sts->sa.top->value == sts->sa.max_value)
			pr_sort_sa_if_top_max_value(sts, buff);
		else if (sts->sa.top->value == sts->sa.min_value)
			pr_sort_sa_if_top_min_value(sts, buff);
		else
			pr_sort_sa_if_top_mid_value(sts, buff);
	}
}
