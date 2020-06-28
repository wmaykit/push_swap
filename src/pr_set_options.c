/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_set_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:23:52 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/14 20:47:38 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	pr_set_options(t_options *m_opions, char **i_av)
{
	int	index_arg;

	index_arg = 1;
	m_opions->list = 0;
	while (i_av[index_arg][0] == '-' && !ft_isdigit(i_av[index_arg][1]))
	{
		m_opions->list |= ft_options(i_av[index_arg]);
		if (m_opions->list & O_FILE && !*m_opions->file.name)
			ft_strcpy(m_opions->file.name, i_av[++index_arg]);
		++index_arg;
	}
}
