/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:19:45 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/14 22:05:22 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int			ft_get_num_err(char **errors)
{
	int		num;

	num = 0;
	if (!errors)
		return (-1);
	while (*errors[num])
		++num;
	return (num);
}

int			ft_error(int err)
{
	char	**errors;
	int		num_err;

	errors = ERROR;
	if ((num_err = ft_get_num_err(errors)) >= 0 && err >= 0 && err < num_err)
	{
		if (err == KO)
			ft_putendl_fd(errors[err], 1);
		else
			ft_putendl_fd(errors[err], 2);
	}
	else
		ft_putendl_fd("Error", 2);
	return (1);
}
