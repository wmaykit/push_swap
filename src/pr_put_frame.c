/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_put_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:51:38 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 17:16:40 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	pr_put_top(t_frame *f)
{
	int		i;

	i = f->start.x;
	while (i < f->end.x)
	{
		V_GOTOXY(i++, f->start.y);
		ft_printf("══");
	}
	V_GOTOXY(f->start.x, f->start.y);
	ft_printf("╔");
	V_GOTOXY(f->partition1.x, f->start.y);
	ft_printf("╦");
	V_GOTOXY(f->end.x, 2);
	ft_printf("╗\n");
}

static void	pr_put_mid(t_frame *f)
{
	int	i;

	i = f->start.y;
	while (++i < f->end.y)
	{
		V_GOTOXY(f->start.x, i);
		ft_printf("║");
		V_GOTOXY(f->partition1.x, i);
		ft_printf("║");
		V_GOTOXY(f->end.x, i);
		ft_printf("║\n");
	}
	i = f->start.x;
	while (i < f->end.x)
	{
		V_GOTOXY(i++, f->partition2.y);
		ft_printf("══");
	}
	V_GOTOXY(f->start.x, f->partition2.y);
	ft_printf("╠");
	V_GOTOXY(f->partition1.x, f->partition2.y);
	ft_printf("╬");
	V_GOTOXY(f->end.x, f->partition2.y);
	ft_printf("╣\n");
}

static void	pr_put_bot(t_frame *f)
{
	int	i;

	i = f->start.x;
	while (i < f->end.x)
	{
		V_GOTOXY(i++, f->end.y);
		ft_printf("══");
	}
	V_GOTOXY(f->start.x, f->end.y);
	ft_printf("╚");
	V_GOTOXY(f->partition1.x, f->end.y);
	ft_printf("╩");
	V_GOTOXY(f->end.x, f->end.y);
	ft_printf("╝\n");
}

void		pr_put_frame(t_frame *f)
{
	ft_printf("\e[38;5;118m");
	pr_put_top(f);
	pr_put_mid(f);
	pr_put_bot(f);
	ft_printf("\e[0m");
}
