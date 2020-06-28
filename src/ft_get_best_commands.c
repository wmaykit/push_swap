/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_best_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 10:05:51 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 14:26:12 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpushswap.h"

static t_commands	ft_union_comands_rrotate(t_commands c)
{
	t_commands		uni;

	ft_bzero(&uni, sizeof(t_commands));
	if (c.select_val.rrotate >= c.insert_place.rrotate)
	{
		uni.c_union.rrotate = c.insert_place.rrotate;
		uni.select_val.rrotate = c.select_val.rrotate - uni.c_union.rrotate;
		uni.insert_place.rrotate = 0;
	}
	else
	{
		uni.c_union.rrotate = c.select_val.rrotate;
		uni.insert_place.rrotate = c.insert_place.rrotate - uni.c_union.rrotate;
		uni.select_val.rrotate = 0;
	}
	uni.num_all_cmd = uni.select_val.rrotate + uni.insert_place.rrotate
														+ uni.c_union.rrotate;
	return (uni);
}

static t_commands	ft_union_comands_rotate(t_commands c)
{
	t_commands		uni;

	ft_bzero(&uni, sizeof(t_commands));
	if (c.select_val.rotate >= c.insert_place.rotate)
	{
		uni.c_union.rotate = c.insert_place.rotate;
		uni.select_val.rotate = c.select_val.rotate - uni.c_union.rotate;
		uni.insert_place.rotate = 0;
	}
	else
	{
		uni.c_union.rotate = c.select_val.rotate;
		uni.insert_place.rotate = c.insert_place.rotate - uni.c_union.rotate;
		uni.select_val.rrotate = 0;
	}
	uni.num_all_cmd = uni.select_val.rotate + uni.insert_place.rotate
														+ uni.c_union.rotate;
	return (uni);
}

static t_commands	ft_r_val_rr_ins(t_commands c)
{
	t_commands		r_val_rr_ins;

	ft_bzero(&r_val_rr_ins, sizeof(t_commands));
	r_val_rr_ins.select_val.rotate = c.select_val.rotate;
	r_val_rr_ins.insert_place.rrotate = c.insert_place.rrotate;
	r_val_rr_ins.num_all_cmd = r_val_rr_ins.select_val.rotate +
								r_val_rr_ins.insert_place.rrotate;
	return (r_val_rr_ins);
}

static t_commands	ft_rr_val_r_ins(t_commands c)
{
	t_commands		rr_val_r_ins;

	ft_bzero(&rr_val_r_ins, sizeof(t_commands));
	rr_val_r_ins.select_val.rrotate = c.select_val.rrotate;
	rr_val_r_ins.insert_place.rotate = c.insert_place.rotate;
	rr_val_r_ins.num_all_cmd = rr_val_r_ins.select_val.rrotate +
								rr_val_r_ins.insert_place.rotate;
	return (rr_val_r_ins);
}

t_commands			ft_get_best_commands(t_commands cmds)
{
	t_commands		rotate;
	t_commands		rrotate;
	t_commands		r_val_rr_ins;
	t_commands		rr_val_r_ins;

	ft_bzero(&rr_val_r_ins, sizeof(t_commands) * 4);
	rotate = ft_union_comands_rotate(cmds);
	rrotate = ft_union_comands_rrotate(cmds);
	r_val_rr_ins = ft_r_val_rr_ins(cmds);
	rr_val_r_ins = ft_rr_val_r_ins(cmds);
	if (rotate.num_all_cmd <= rrotate.num_all_cmd &&
			rotate.num_all_cmd <= r_val_rr_ins.num_all_cmd &&
				rotate.num_all_cmd <= rr_val_r_ins.num_all_cmd)
		return (rotate);
	else if (rrotate.num_all_cmd <= rotate.num_all_cmd &&
				rrotate.num_all_cmd <= r_val_rr_ins.num_all_cmd &&
					rrotate.num_all_cmd <= rr_val_r_ins.num_all_cmd)
		return (rrotate);
	else if (r_val_rr_ins.num_all_cmd <= rotate.num_all_cmd &&
				r_val_rr_ins.num_all_cmd <= rotate.num_all_cmd &&
					r_val_rr_ins.num_all_cmd <= rr_val_r_ins.num_all_cmd)
		return (r_val_rr_ins);
	else
		return (rr_val_r_ins);
}
