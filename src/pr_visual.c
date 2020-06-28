/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 21:42:25 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 17:11:31 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	pr_print_ctack(t_stack *stack, t_point *xy)
{
	t_lst	*iterator;
	int		i;
	int		y;

	i = 0;
	y = xy->y;
	iterator = stack->top;
	while (i++ < stack->size)
	{
		V_GOTOXY(xy->x - iterator->sweeps, y);
		ft_printf("\e[48;5;%dm%*s", iterator->color, iterator->sweeps, "");
		V_GOTOXY(xy->x, y);
		ft_printf("%*s", iterator->sweeps + 1, "");
		V_GOTOXY(xy->x, y++);
		ft_printf("%d\e[0m", iterator->value);
		iterator = iterator->next;
	}
}

static void	pr_print_info(t_checker *checker, int oper_id)
{
	char	**opr;

	opr = (char*[]){"SA", "SB", "SS", "PA", "PB", "RA", "RB", "RR",
													"RRA", "RRB", "RRR"};
	V_GOTOXY(checker->visual.info[0].x, checker->visual.info[0].y);
	ft_printf("%-20s = %d\n", "Size stack A", checker->stacks.sa.size);
	V_GOTOXY(checker->visual.info[1].x, checker->visual.info[1].y);
	ft_printf("%-20s = %d\n", "Size stack B", checker->stacks.sb.size);
	V_GOTOXY(checker->visual.info[2].x, checker->visual.info[2].y);
	ft_printf("%-20s = %d\n", "Number operations", checker->oper_num);
	V_GOTOXY(checker->visual.info[3].x, checker->visual.info[3].y);
	ft_printf("%-20s = %s \n", "Current operations", opr[oper_id]);
	V_GOTOXY(checker->visual.info[4].x, checker->visual.info[4].y);
	if (!ft_check_sort(&checker->stacks))
		ft_printf("\e[38;5;196m%-20s %s\e[0m\n", "NO SORT", "╳");
	else
		ft_printf("\e[38;5;10m%-20s %s\e[0m\n", "IS SORT", "✓");
}

static void	pr_put_ascii(t_visual *visual)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		V_GOTOXY(visual->p_ascii_sa.x, visual->p_ascii_sa.y + i);
		ft_printf("\e[38;5;198m%s\e[0m", visual->ascii_sa[i]);
		V_GOTOXY(visual->p_ascii_sb.x, visual->p_ascii_sb.y + i);
		ft_printf("\e[38;5;63m%s\e[0m", visual->ascii_sb[i]);
		++i;
	}
}

void		pr_visual(t_checker *checker, int oper_id)
{
	ft_printf("\e[8;%d;%d;t\e[?7l", checker->visual.window.height,
										checker->visual.window.width);
	V_CLEAR();
	V_HOME();
	pr_put_frame(&checker->visual.frame);
	pr_put_ascii(&checker->visual);
	pr_print_ctack(&checker->stacks.sa, &checker->visual.start_sa);
	pr_print_ctack(&checker->stacks.sb, &checker->visual.start_sb);
	pr_print_info(checker, oper_id);
	V_GOTOXY(1, 150);
}
