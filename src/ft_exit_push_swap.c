/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:22:18 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/12 16:39:39 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_exit_push_swap(t_push_swap *push_swap, int status)
{
	ft_memdel_stacks(&push_swap->stacks);
	if (push_swap->options.file.fd > 2)
		close(push_swap->options.file.fd);
	if (push_swap->sort_nbr)
	{
		free(push_swap->sort_nbr);
		push_swap->sort_nbr = NULL;
	}
	if (status == ERROR_ERROR)
		return (ft_error(0));
	return (0);
}
