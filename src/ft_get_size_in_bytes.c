/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_in_bytes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:17:39 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/04 12:58:30 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_get_size_in_bytes(t_name_cmd cmd)
{
	if (cmd)
	{
		if (cmd & 0xFF0000)
			return (4);
		else
			return (3);
	}
	return (0);
}
