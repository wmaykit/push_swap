/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perform_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:30:49 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 15:42:33 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_perform_operations(t_checker *checker)
{
	int	id;

	id = 0;
	if (checker->options.list & O_VISUAL)
		pr_put_params_for_visual(checker);
	while ((id = ft_get_operations(checker)) >= 0)
	{
		((t_operations*)checker->operations)[id](&checker->stacks);
		++checker->oper_num;
		if (checker->options.list & O_VISUAL)
		{
			pr_visual(checker, id);
			system("sleep 0.05");
		}
	}
	if (id == -2)
		return (0);
	return (1);
}
