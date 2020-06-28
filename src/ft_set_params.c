/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:52:19 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 19:04:25 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

void		ft_set_params(t_checker *checker)
{
	void	*tmp;

	ft_bzero(checker, sizeof(t_checker));
	tmp = (t_all_oper){OPERATION_FUNC};
	ft_memmove(checker->operations, tmp, sizeof(t_operations) * 11);
	tmp = (unsigned[]){OPERATIONS};
	ft_memmove(checker->operations_id, tmp, sizeof(unsigned) * 11);
}
