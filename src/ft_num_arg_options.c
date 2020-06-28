/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_arg_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:50:13 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 15:41:03 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int				ft_num_arg_options(char **i_av)
{
	unsigned	options;
	int			o_index;

	o_index = 0;
	while (i_av[o_index + 1][0] == '-')
	{
		if ((options = ft_options(i_av[o_index + 1])) == O_ERROR)
			return (o_index);
		if (options & O_FILE)
			++o_index;
		++o_index;
	}
	return (o_index);
}
