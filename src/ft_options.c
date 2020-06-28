/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:45:46 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/12 13:14:41 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

unsigned	ft_options(char *options_ascii)
{
	unsigned	options;

	options = 0;
	if (options_ascii[0] == '-')
	{
		++options_ascii;
		if (!*options_ascii)
			return (O_ERROR);
		while (*options_ascii)
		{
			if (*options_ascii == 'f')
				options |= 0x1;
			else if (*options_ascii == 'v')
				options |= 0x2;
			else
				return (O_ERROR);
			++options_ascii;
		}
	}
	return (options);
}
