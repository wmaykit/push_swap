/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_print_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:37:52 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/11 22:57:34 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	pr_print_buff(t_buff *buff)
{
	if (buff->size_bytes > 0)
	{
		write(buff->fd_out, buff->buff, buff->size_bytes);
		ft_bzero(buff->buff, buff->size_bytes);
		buff->current = buff->buff;
		buff->size_bytes = 0;
	}
}
