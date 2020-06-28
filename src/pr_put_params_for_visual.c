/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_put_params_for_visual.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 23:21:39 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/14 14:11:24 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	pr_put_part(t_part *m_parts, int *i_sort_nbr, int i_size, int i_max)
{
	m_parts[0].min = *i_sort_nbr;
	m_parts[0].max = i_sort_nbr[(i_size / 3)];
	m_parts[1].min = i_sort_nbr[(i_size / 3)];
	m_parts[1].max = i_sort_nbr[(i_size / 3) * 2];
	m_parts[2].min = m_parts[1].max;
	m_parts[2].max = i_max;
}

static void	pr_put_color_and_sweeps(t_stacks *sts, int *sort_nbr)
{
	t_lst	*walk;
	t_part	part[3];
	int		j;
	int		i;

	i = 0;
	pr_put_part(part, sort_nbr, sts->sa.size, sts->sa.max_value);
	walk = sts->sa.top;
	while (i++ < sts->sa.size)
	{
		j = 0;
		while (j < sts->sa.size && walk->value != sort_nbr[j])
			++j;
		walk->sweeps = j;
		if (walk->value >= part[0].min && walk->value < part[0].max)
			walk->color = 215;
		else if (walk->value >= part[1].min && walk->value < part[1].max)
			walk->color = 210;
		else if (ft_is_part(walk->value, &part[2]))
			walk->color = 199;
		else
			walk->color = 0;
		walk = walk->next;
	}
}

void		pr_put_params_for_visual(t_checker *checker)
{
	pr_put_visual_data(checker);
	pr_put_color_and_sweeps(&checker->stacks, checker->sort_nbr);
}
