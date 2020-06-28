/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:20:01 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/14 21:57:03 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_exit_checker(t_checker *checker, int status)
{
	int	i;

	i = 0;
	ft_memdel_stacks(&checker->stacks);
	if (checker->options.file.fd > 2)
		close(checker->options.file.fd);
	while (checker->visual.ascii_sa[i])
		free(checker->visual.ascii_sa[i++]);
	i = 0;
	while (checker->visual.ascii_sb[i])
		free(checker->visual.ascii_sb[i++]);
	if (checker->sort_nbr)
	{
		free(checker->sort_nbr);
		checker->sort_nbr = NULL;
	}
	if (checker->options.list & O_VISUAL)
		return (0);
	if (status == OK)
	{
		ft_printf("OK\n");
		return (0);
	}
	return (ft_error(status));
}
