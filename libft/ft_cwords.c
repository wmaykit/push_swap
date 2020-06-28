/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cwords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:04:35 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/18 17:47:08 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_cwords(char *s, char c)
{
	int i;
	int w;

	if (!s)
		return (0);
	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}