/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:16:00 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/19 19:56:31 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		main(int ac, char **av)
{
	t_push_swap	push_swap;

	ft_bzero(&push_swap, sizeof(t_push_swap));
	if (ac > 1)
	{
		push_swap.buff.current = push_swap.buff.buff;
		push_swap.buff.end = push_swap.buff.buff + (BUFF_SIZE_PS - 5);
		push_swap.buff.fd_out = 1;
		if (!ft_valid(ac, av, "push_swap") ||
				!pr_create_sa(av, ac - 1, &push_swap.stacks))
			return (ft_exit_push_swap(&push_swap, ERROR_ERROR));
		pr_set_options(&push_swap.options, av);
		if (!(push_swap.sort_nbr = ft_get_sort_nbr(&push_swap.stacks.sa)) ||
				ft_has_equal(push_swap.sort_nbr, push_swap.stacks.sa.size - 1))
			return (ft_exit_push_swap(&push_swap, ERROR_ERROR));
		if (push_swap.options.list & O_FILE)
		{
			if (!pr_open_file(&push_swap.options.file, O_CREAT))
				return (ft_exit_push_swap(&push_swap, ERROR_ERROR));
			push_swap.buff.fd_out = push_swap.options.file.fd;
		}
		if (!ft_check_sort(&push_swap.stacks))
			pr_sort_stack_and_print_command(&push_swap);
	}
	return (ft_exit_push_swap(&push_swap, OK));
}
