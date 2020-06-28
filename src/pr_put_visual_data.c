/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_put_visual_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:22:36 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 17:17:52 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static void	pr_set_point_info(t_visual *m_visual)
{
	m_visual->start_sb.y = m_visual->start_sa.y;
	m_visual->info[0].x = m_visual->frame.end.x + 5;
	m_visual->info[0].y = m_visual->frame.end.y / 2;
	m_visual->info[1].x = m_visual->info[0].x;
	m_visual->info[1].y = m_visual->info[0].y + 1;
	m_visual->info[2].x = m_visual->info[1].x;
	m_visual->info[2].y = m_visual->info[1].y + 2;
	m_visual->info[3].x = m_visual->info[2].x;
	m_visual->info[3].y = m_visual->info[2].y + 1;
	m_visual->info[4].x = m_visual->info[3].x;
	m_visual->info[4].y = m_visual->info[3].y + 3;
}

static void	pr_set_visual(t_visual *m_visual)
{
	m_visual->window.width = 468;
	m_visual->window.height = 140;
	m_visual->frame.sweeps.x = 2;
	m_visual->frame.sweeps.y = 2;
	m_visual->sweeps_left = 50;
	m_visual->frame.size.width = m_visual->window.width;
	m_visual->frame.size.height = m_visual->window.height;
	m_visual->frame.start.x = m_visual->frame.sweeps.x;
	m_visual->frame.start.y = m_visual->frame.sweeps.y;
	m_visual->frame.end.x = m_visual->window.width - m_visual->sweeps_left;
	m_visual->frame.end.y = m_visual->window.height - m_visual->frame.sweeps.y;
	m_visual->frame.partition1.x = m_visual->frame.end.x / 2;
	m_visual->frame.partition2.y = m_visual->frame.sweeps.y + 14;
	m_visual->start_sa.x = m_visual->frame.partition1.x / 2;
	m_visual->start_sa.y = m_visual->frame.partition2.y + 5;
	m_visual->start_sb.x = m_visual->start_sa.x +
						(m_visual->frame.end.x - m_visual->frame.partition1.x);
	pr_set_point_info(m_visual);
	m_visual->p_ascii_sa.x = m_visual->start_sa.x - 30;
	m_visual->p_ascii_sa.y = m_visual->frame.partition2.y - (3 + 7);
	m_visual->p_ascii_sb.x = m_visual->start_sb.x - 30;
	m_visual->p_ascii_sb.y = m_visual->frame.partition2.y - (3 + 7);
}

static void	pr_set_ascii_art(t_checker *checker)
{
	int i;
	int	fd;

	i = 0;
	if ((fd = open("./includes/ascii_name_sa", O_RDONLY)) > 0)
	{
		while (i < 7 && get_next_line(fd, (checker->visual.ascii_sa + i)) > 0)
			++i;
		close(fd);
	}
	i = 0;
	if ((fd = open("./includes/ascii_name_sb", O_RDONLY)) > 0)
	{
		while (i < 7 && get_next_line(fd, checker->visual.ascii_sb + i) > 0)
			++i;
		close(fd);
	}
}

void		pr_put_visual_data(t_checker *checker)
{
	pr_set_visual(&checker->visual);
	pr_set_ascii_art(checker);
}
