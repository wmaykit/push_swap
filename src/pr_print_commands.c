/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_print_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:49:31 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 17:06:44 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	pr_print_commands(t_commands *c, int w, int w2, char *sign)
{
	ft_printf("%s\n", sign);
	ft_printf("%-*s = %*d", w, "select_val.rotate",
								w2, c->select_val.rotate);
	ft_printf(" | %-*s = %*d\n", w, "insert_place.rotate",
								w2, c->insert_place.rotate);
	ft_printf("%-*s = %*d", w, "select_val.rrotate",
								w2, c->select_val.rrotate);
	ft_printf(" | %-*s = %*d\n", w, "insert_place.rrotate",
								w2, c->insert_place.rrotate);
	ft_printf("%-*s = %*d\n", w, "c_union.rotate",
								w2, c->c_union.rotate);
	ft_printf("%-*s = %*d\n", w, "c_union.rrotate",
								w2, c->c_union.rrotate);
	ft_printf("%30s = %5d\n\n", "num_all_cmd", c->num_all_cmd);
}
