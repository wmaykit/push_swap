/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 01:02:29 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 15:57:20 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static t_boolean	ft_valid_arg(int i_ac, char **i_av, int i_index_begin)
{
	char			*iterator;
	int				index;

	index = i_index_begin;
	while (index < i_ac)
	{
		iterator = i_av[index];
		while (*iterator)
		{
			if (!ft_isdigit(*iterator))
				if (*iterator != '-')
					if (*iterator != '+')
						if (*iterator != ' ')
							return (FALSE);
			if ((*iterator == '-' || *iterator == '+') &&
					!ft_isdigit(iterator[1]))
				return (FALSE);
			++iterator;
		}
		++index;
	}
	return (TRUE);
}

static int			ft_valid_options_checker(int i_ac, char **i_av)
{
	int				index;
	unsigned		tmp;
	unsigned		options;

	index = 1;
	options = 0;
	while (i_av[index][0] == '-' && !ft_isdigit(i_av[index][1]))
	{
		tmp = options;
		if ((options = ft_options(i_av[index])) == O_ERROR ||
				(tmp & O_FILE) & (options & O_FILE) ||
					options & ~(O_VISUAL + O_FILE))
			return (-1);
		if (options & O_FILE)
			++index;
		++index;
		if (index >= i_ac)
			return (-1);
	}
	return (index);
}

static int			ft_valid_options_push_swap(int i_ac, char **i_av)
{
	int				index;
	unsigned		tmp;
	unsigned		options;

	index = 1;
	options = 0;
	while (i_av[index][0] == '-' && !ft_isdigit(i_av[index][1]))
	{
		tmp = options;
		if ((options = ft_options(i_av[index])) == O_ERROR ||
				(tmp & O_FILE) & (options & O_FILE) ||
					options & ~O_FILE)
			return (-1);
		if (options & O_FILE)
			++index;
		++index;
		if (index >= i_ac)
			return (-1);
	}
	return (index);
}

t_boolean			ft_valid(int i_ac, char **i_av, char *i_prog)
{
	int				index;

	index = 1;
	if ((*(unsigned long*)i_prog & ~0xFF00000000000000) == 0x72656863656863)
	{
		if ((index = ft_valid_options_checker(i_ac, i_av)) < 0)
			return (FALSE);
	}
	else if (*(unsigned long*)i_prog == 0x6177735f68737570)
	{
		if ((index = ft_valid_options_push_swap(i_ac, i_av)) < 0)
			return (FALSE);
	}
	return (ft_valid_arg(i_ac, i_av, index));
}
