/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:40:46 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 17:07:11 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

t_boolean	pr_open_file(t_file *m_file, int i_flag)
{
	if (i_flag == O_CREAT)
	{
		ft_strlcat(m_file->name, ".ps", 100);
		if ((m_file->fd = open(m_file->name,
									O_WRONLY | O_TRUNC | O_CREAT, 0x1FF) < 0))
			return (FALSE);
		i_flag = O_WRONLY;
	}
	if ((m_file->fd = open(m_file->name, i_flag)) < 0)
		return (FALSE);
	return (TRUE);
}
