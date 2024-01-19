/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_create_sa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:00:08 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 17:05:36 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static int			pr_del_mem(char ***m_nums, int i_index)
{
	int				index_e;

	if (m_nums && *m_nums && **m_nums)
	{
		while (i_index >= 0)
		{
			index_e = 0;
			while (m_nums[i_index][index_e])
			{
				if (*m_nums[i_index][index_e])
					free(m_nums[i_index][index_e]);
				++index_e;
			}
			if (m_nums[i_index])
				free(m_nums[i_index]);
			--i_index;
		}
		if (m_nums)
			free(m_nums);
	}
	return (0);
}

static char			***ft_get_separated_nums(char **i_stack, int i_len)
{
	char			***o_nums;
	int				index_n;
	int				index_s;
	int				len_nums;

	index_n = 0;
	index_s = i_len;
	len_nums = i_len - ft_num_arg_options(i_stack);
	if (len_nums > 0)
	{
		if (!(o_nums = (char ***)malloc(sizeof(char**) * (len_nums + 1))))
			return (NULL);
		while (index_n < len_nums)
		{
			if (!(o_nums[index_n++] = ft_strsplit(i_stack[index_s--], ' ')))
			{
				pr_del_mem(o_nums, index_n - 1);
				return (NULL);
			}
		}
		o_nums[len_nums] = 0;
		return (o_nums);
	}
	return (NULL);
}

static t_boolean	ft_is_overflow(int i_value, char *i_value_ascii)
{
	char			*iterator;
	long			value;

	iterator = i_value_ascii;
	if ((value = i_value) < 0)
	{
		if (*iterator != '-')
			return (TRUE);
		value = -value;
	}
	while (*iterator)
		++iterator;
	if (!*iterator)
		--iterator;
	if (iterator < i_value_ascii)
		return (0);
	while (ft_isdigit(*iterator))
	{
		if ((value % 10 + '0') != *iterator--)
			return (TRUE);
		value = value / 10;
	}
	return (FALSE);
}

static int			ft_index_last_num(char **i_nums)
{
	int				o_last_num;

	o_last_num = 0;
	while (i_nums[o_last_num])
		++o_last_num;
	return (o_last_num);
}

int					pr_create_sa(char **i_nums, int i_len, t_stacks *i_sts)
{
	int				value;
	char			***nasc;
	int				index_e;
	int				index_v;

	ft_bzero(&index_v, sizeof(int) * 2);
	if (!(nasc = ft_get_separated_nums(i_nums, i_len)))
		return (0);
	while (nasc[index_v])
	{
		index_e = ft_index_last_num(nasc[index_v]);
		while (index_e)
		{
			value = ft_atoi(nasc[index_v][--index_e]);
			if (!ft_create_new_lst(value, &i_sts->sa) ||
					ft_is_overflow(value, nasc[index_v][index_e]))
				return (ft_memdel_stacks(i_sts) | pr_del_mem(nasc, i_len - 1));
			++i_sts->sa.size;
		}
		++index_v;
	}
	pr_del_mem(nasc, index_v - 1);
	i_sts->sa.max_value = ft_max_value_stack(&i_sts->sa);
	i_sts->sa.min_value = ft_min_value_stack(&i_sts->sa);
	return (1);
}
