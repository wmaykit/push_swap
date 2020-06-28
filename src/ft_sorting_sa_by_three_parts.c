/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_sa_by_three_parts.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 20:16:07 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 16:17:39 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	pr_separate(t_part *min, t_part *mid, t_part *max, t_push_swap *ps)
{
	min->size = ps->stacks.sa.size / 3;
	min->min = *ps->sort_nbr;
	min->max = ps->sort_nbr[min->size - 1];
	mid->size = min->size;
	mid->min = ps->sort_nbr[min->size];
	mid->mid = ps->sort_nbr[ps->stacks.sa.size / 2];
	mid->max = ps->sort_nbr[mid->size * 2 - 1];
	max->size = min->size + ps->stacks.sa.size % 3;
	max->min = ps->sort_nbr[mid->size * 2];
	max->max = ps->sort_nbr[mid->size * 2 + max->size];
}

static void	pr_push_max_part_sb(t_push_swap *push_swap, t_part mid)
{
	while (push_swap->stacks.sa.size > 3)
	{
		if (push_swap->stacks.sa.top->value != mid.mid
				&& push_swap->stacks.sa.top->value !=
				push_swap->stacks.sa.max_value
				&& push_swap->stacks.sa.top->value != *push_swap->sort_nbr)
			pr_pb_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
		else
			pr_ra_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
	}
}

static void	ft_pre_sorting(t_push_swap *push_swap)
{
	t_part	min;
	t_part	mid;
	t_part	max;

	pr_separate(&min, &mid, &max, push_swap);
	while (push_swap->stacks.sa.size > max.size + 2)
	{
		if (ft_is_part(push_swap->stacks.sa.top->value, &mid)
				&& push_swap->stacks.sa.top->value != mid.mid)
			pr_pb_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
		else if (ft_is_part(push_swap->stacks.sa.top->value, &min)
				&& push_swap->stacks.sa.top->value != *push_swap->sort_nbr)
		{
			if (push_swap->stacks.sb.size < 2)
				pr_pb_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
			else
			{
				pr_pb_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
				pr_rb_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
			}
		}
		else
			pr_ra_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
	}
	pr_push_max_part_sb(push_swap, mid);
}

static void	pr_push_sa_and_soring(t_push_swap *ps)
{
	t_commands	low_num_cmd;

	low_num_cmd = ft_get_low_num_cmd(&ps->stacks.sa, &ps->stacks.sb);
	pr_execute_command(low_num_cmd, ps, 'A');
	pr_pa_and_add_to_buff(&ps->stacks, &ps->buff);
	ps->stacks.sb.max_value = ft_max_value_stack(&ps->stacks.sb);
	ps->stacks.sb.min_value = ft_min_value_stack(&ps->stacks.sb);
}

void		ft_sorting_sa_by_three_parts(t_push_swap *push_swap)
{
	int		cmd_up;

	ft_pre_sorting(push_swap);
	push_swap->stacks.sa.max_value = ft_max_value_stack(&push_swap->stacks.sa);
	push_swap->stacks.sa.min_value = ft_min_value_stack(&push_swap->stacks.sa);
	pr_sort_only_three_values_sa(&push_swap->stacks, &push_swap->buff);
	while (push_swap->stacks.sb.size)
		pr_push_sa_and_soring(push_swap);
	cmd_up = ft_get_index_value_in_stack(&push_swap->stacks.sa,
									ft_min_value_stack(&push_swap->stacks.sa));
	if (cmd_up > push_swap->stacks.sa.size / 2)
	{
		cmd_up = push_swap->stacks.sa.size - cmd_up;
		while (cmd_up-- > 0)
			pr_rra_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
	}
	else
		while (cmd_up-- > 0)
			pr_ra_and_add_to_buff(&push_swap->stacks, &push_swap->buff);
}
