/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_add_command_to_buff.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:05:00 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/04 14:34:13 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	pr_add_command_to_buff(t_buff *buff, t_name_cmd cmd)
{
	int	size_name;

	if (buff->current >= buff->end)
		pr_print_buff(buff);
	if ((size_name = ft_get_size_in_bytes(cmd)))
	{
		cmd = ft_end_new_line(cmd);
		ADD_CMD_TO_BUFF(cmd, buff->current);
		buff->current += size_name;
		buff->size_bytes += size_name;
	}
}
