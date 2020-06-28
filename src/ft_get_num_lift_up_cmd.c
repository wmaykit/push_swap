/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_num_lift_up_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 22:45:43 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/05 18:53:57 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

t_command	ft_get_num_lift_up_cmd(t_stack *st, int index_in_stack)
{
	t_command	res;

	ft_bzero(&res, sizeof(t_command));
	if (index_in_stack > 0)
	{
		res.rotate = index_in_stack;
		res.rrotate = st->size - index_in_stack;
	}
	return (res);
}
