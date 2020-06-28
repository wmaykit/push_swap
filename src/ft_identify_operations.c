/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:11:46 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/11 16:11:12 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int		ft_identify_operations(t_checker *checker, char **operations)
{
	unsigned	*current;
	unsigned	*end;
	unsigned	code;

	current = checker->operations_id;
	end = current + 11;
	if (!(*(unsigned *)*operations & 0xFF0000))
		code = *(unsigned *)*operations & ~0xFF000000;
	else
		code = *(unsigned *)*operations;
	while (current < end)
	{
		if (*current == code)
		{
			free(*operations);
			*operations = NULL;
			return (current - checker->operations_id);
		}
		++current;
	}
	free(*operations);
	*operations = NULL;
	return (-2);
}
