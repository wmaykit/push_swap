/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:30:39 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/19 19:55:48 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int				main(int ac, char **av)
{
	t_checker	checker;

	if (ac > 1)
	{
		ft_set_params(&checker);
		if (!ft_valid(ac, av, "checher") ||
				!pr_create_sa(av, ac - 1, &checker.stacks))
			return (ft_exit_checker(&checker, ERROR_ERROR));
		pr_set_options(&checker.options, av);
		if (checker.options.list & O_FILE)
			if (!pr_open_file(&checker.options.file, O_RDONLY))
				return (ft_exit_checker(&checker, ERROR_ERROR));
		if (!(checker.sort_nbr = ft_get_sort_nbr(&checker.stacks.sa)) ||
				ft_has_equal(checker.sort_nbr, checker.stacks.sa.size - 1) ||
					!ft_perform_operations(&checker))
			return (ft_exit_checker(&checker, ERROR_ERROR));
		if (((checker.is_sorted && checker.oper_num > 0) ||
									!ft_check_sort(&checker.stacks)))
			return (ft_exit_checker(&checker, KO));
		else
			return (ft_exit_checker(&checker, OK));
	}
	return (0);
}
