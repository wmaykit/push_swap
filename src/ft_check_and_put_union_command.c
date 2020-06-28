/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_install_union_command.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:40:07 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/05 18:39:33 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	ft_check_and_put_union_command(t_command *union_com, t_command *com1,
																t_command *com2)
{
	if (com1->rotate >= com2->rotate)
	{
		union_com->rotate = com2->rotate;
		com2->rotate = 0;
		com1->rotate = com1->rotate - union_com->rotate;
	}
	else
	{
		union_com->rotate = com1->rotate;
		com1->rotate = 0;
		com2->rotate = com2->rotate - union_com->rotate;
	}
	if (com1->rrotate >= com2->rrotate)
	{
		union_com->rrotate = com2->rrotate;
		com2->rrotate = 0;
		com1->rrotate = com1->rrotate - union_com->rrotate;
	}
	else
	{
		union_com->rrotate = com1->rrotate;
		com1->rrotate = 0;
		com2->rrotate = com2->rotate - union_com->rotate;
	}
}
