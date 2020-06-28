/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:04:35 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 17:21:14 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void	pr_sort_stack_and_print_command(t_push_swap *push_swap)
{
	if (push_swap->stacks.sa.size == 3)
		pr_sort_only_three_values_sa(&push_swap->stacks, &push_swap->buff);
	else if (push_swap->stacks.sa.size > 3 && push_swap->stacks.sa.size <= 5)
		pr_sort_only_five_values_sa(push_swap);
	else
		ft_sorting_sa_by_three_parts(push_swap);
	pr_print_buff(&push_swap->buff);
}
