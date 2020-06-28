/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:35:26 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/12 16:19:05 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

int			ft_get_operations(t_checker *checker)
{
	char	*operations;
	int		ret;
	int		fd;

	operations = NULL;
	if (checker->options.list & O_FILE)
		fd = checker->options.file.fd;
	else
		fd = 0;
	ret = get_next_line(fd, &operations);
	if (ret < 0)
	{
		if (operations)
			free(operations);
		return (-2);
	}
	else if (!ret)
	{
		if (operations)
			free(operations);
		return (-1);
	}
	return (ft_identify_operations(checker, &operations));
}
