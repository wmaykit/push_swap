/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftpushswap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:17:28 by wmaykit           #+#    #+#             */
/*   Updated: 2019/10/18 19:05:18 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPUSHSWAP_H
# define LIBFTPUSHSWAP_H

# include "libft.h"
# include "libftprintf.h"
# include "get_next_line.h"
# include <fcntl.h>

# define ERROR_NAME 	"Error", "KO"
# define ERROR 			(char *[]){ERROR_NAME, "\0"}
# define ADD_CMD_TO_BUFF(cmd, buff) *((unsigned *)buff) = cmd

# define ERROR_ERROR	0x0
# define KO				0x1
# define OK				0x3E8

# define O_VISUAL		0x00000002
# define O_FILE			0x00000001
# define O_ERROR		0xFFFFFFFF

# define TRUE			1
# define FALSE			0

/*
** CODE OPERATIONS
*/
# define SA				0x00006173
# define SB				0x00006273
# define SS				0x00007373
# define PA				0x00006170
# define PB				0x00006270
# define RA				0x00006172
# define RB				0x00006272
# define RR				0x00007272
# define RRA			0x00617272
# define RRB			0x00627272
# define RRR			0x00727272
# define OPERATIONS		SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR

/*
** ARRY FUNCTIONS OPERATIONS
*/
# define SWAP_FUNC		ft_swap_sa, ft_swap_sb, ft_swap_sa_and_sb
# define PUSH_FUNC		ft_push_sa, ft_push_sb
# define ROTATE_FUNC	ft_rotate_sa, ft_rotate_sb, ft_rotate_sa_and_sb
# define R_ROTATE_FUNC	ft_rrotate_sa, ft_rrotate_sb, ft_rrotate_sa_and_sb
# define OPERATION_FUNC	SWAP_FUNC, PUSH_FUNC, ROTATE_FUNC, R_ROTATE_FUNC

# define BUFF_SIZE_PS	1024

/*
** VISUALIZATION
*/
# define V_HOME()		ft_printf("\e[H")
# define V_CLEAR()		ft_printf("\e[2J")
# define V_GOTOXY(x, y)	ft_printf("\e[%d;%dH", y, x)

typedef unsigned char	t_boolean;
typedef unsigned		t_flag;
typedef unsigned		t_name_cmd;

typedef struct		s_lst
{
	int				value;
	int				color;
	int				sweeps;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_stack
{
	int				size;
	int				max_value;
	int				min_value;
	t_lst			*top;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			sa;
	t_stack			sb;

}					t_stacks;

typedef struct		s_part
{
	int				min;
	int				mid;
	int				max;
	int				size;
}					t_part;

typedef struct		s_file
{
	int				fd;
	char			name[100];
}					t_file;

typedef struct		s_options
{
	unsigned		list;
	t_file			file;
}					t_options;

typedef struct		s_ft_size
{
	int				width;
	int				height;
}					t_ft_size;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_frame
{
	t_ft_size		size;
	t_point			sweeps;
	t_point			start;
	t_point			end;
	t_point			partition1;
	t_point			partition2;
}					t_frame;

typedef struct		s_visual
{
	t_ft_size		window;
	t_frame			frame;
	t_point			start_sa;
	t_point			start_sb;
	t_point			info[5];
	t_point			p_ascii_sa;
	t_point			p_ascii_sb;
	char			*ascii_sa[8];
	char			*ascii_sb[8];
	int				sweeps_left;
}					t_visual;

typedef struct		s_checker
{
	t_stacks		stacks;
	unsigned long	oper_num;
	unsigned		operations_id[11];
	void			*operations[11];
	int				*sort_nbr;
	t_visual		visual;
	t_options		options;
	t_boolean		is_sorted;
}					t_checker;

typedef struct		s_buff
{
	char			buff[BUFF_SIZE_PS];
	char			*current;
	char			*end;
	int				fd_out;
	int				size_bytes;
}					t_buff;

typedef struct		s_push_swap
{
	t_stacks		stacks;
	t_buff			buff;
	t_part			part[10];
	t_options		options;
	int				*sort_nbr;
	int				nparts;
}					t_push_swap;

typedef struct		s_num_and_index
{
	int				num;
	int				index;
}					t_num_and_index;

typedef struct		s_command
{
	int				rotate;
	int				rrotate;
}					t_command;

typedef struct		s_commands
{
	t_command		select_val;
	t_command		insert_place;
	t_command		c_union;
	int				num_all_cmd;
}					t_commands;

typedef void	(*t_operations)(t_stacks*);
typedef t_operations	t_all_oper[];

/*
** SWAP
*/
void				ft_swap_sa(t_stacks *stacks);
void				ft_swap_sb(t_stacks *stacks);
void				ft_swap_first_two(t_stack *stack);
void				ft_swap_sa_and_sb(t_stacks *stacks);

/*
** PUSH
*/
void				ft_push_sa(t_stacks *stacks);
void				ft_push_sb(t_stacks *stacks);
void				ft_push(t_stack *from, t_stack *here);

/*
** ROTATE
*/
void				ft_rotate_sa(t_stacks *stacks);
void				ft_rotate_sb(t_stacks *stacks);
void				ft_rotate_stack(t_stack *stack);
void				ft_rotate_sa_and_sb(t_stacks *stacks);

/*
** REVERSE ROTATE
*/
void				ft_rrotate_sa(t_stacks *stacks);
void				ft_rrotate_sb(t_stacks *stacks);
void				ft_rrotate_stack(t_stack *stack);
void				ft_rrotate_sa_and_sb(t_stacks *stacks);

/*
** These are the procedure: SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR.
** Which are combined with the addition to the output buffer.
*/
void				pr_sa_and_add_to_buff(t_stacks *stacks, t_buff *buff);
void				pr_sb_and_add_to_buff(t_stacks *stacks, t_buff *buff);
void				pr_ss_and_add_to_buff(t_stacks *stacks, t_buff *buff);

void				pr_pa_and_add_to_buff(t_stacks *stacks, t_buff *buff);
void				pr_pb_and_add_to_buff(t_stacks *stacks, t_buff *buff);

void				pr_ra_and_add_to_buff(t_stacks *stacks, t_buff *buff);
void				pr_rb_and_add_to_buff(t_stacks *stacks, t_buff *buff);
void				pr_rr_and_add_to_buff(t_stacks *stacks, t_buff *buff);

void				pr_rra_and_add_to_buff(t_stacks *stacks, t_buff *buff);
void				pr_rrb_and_add_to_buff(t_stacks *stacks, t_buff *buff);
void				pr_rrr_and_add_to_buff(t_stacks *stacks, t_buff *buff);

/*
** Is procedures sorting only three and five values in stack A.
*/
void				pr_sort_only_five_values_sa(t_push_swap *ps);
void				pr_sort_only_three_values_sa(t_stacks *sts, t_buff *buff);

/*
** Main sorting procedurei.
*/
void				ft_sorting_sa_by_three_parts(t_push_swap *push_swap);

/*
** Functions and procedures are mandatory for sorting and calculating
** the minimum number of operations.
*/
t_commands			ft_get_low_num_cmd(t_stack *f, t_stack *h);
t_commands			ft_get_best_commands(t_commands commands);
t_command			ft_get_num_lift_up_cmd(t_stack *st, int index_in_stack);
t_boolean			ft_is_part(int num, t_part *part);
void				pr_sort_stack_and_print_command(t_push_swap *push_swap);
void				pr_execute_command(t_commands c, t_push_swap *ps, char in);
int					ft_get_index_value_in_stack(t_stack *st, int value);
int					ft_get_insert_index_in_stack(t_stack *st, int insert_value);
int					ft_max_value_stack(t_stack *st);
int					ft_min_value_stack(t_stack *st);

/*
** Is functions and procedure for managing the output buffer
*/
t_name_cmd			ft_end_new_line(t_name_cmd cmd);
void				pr_add_command_to_buff(t_buff *buff, t_name_cmd cmd);
void				pr_print_buff(t_buff *buff);
int					ft_get_size_in_bytes(t_name_cmd cmd);

/*
** System procedures and functions
*/
t_boolean			pr_open_file(t_file *m_file, int i_flag);
t_lst				*ft_cut_top_node(t_stack *from);
void				ft_set_params(t_checker *checker);
int					pr_create_sa(char **values, int len, t_stacks *stacks);
int					ft_create_new_lst(int value, t_stack *stack);
int					ft_get_operations(t_checker *checker);

int					ft_identify_operations(t_checker *checker, char **oper);
int					ft_perform_operations(t_checker *checker);

int					ft_exit_push_swap(t_push_swap *push_swap, int status);
int					ft_exit_checker(t_checker *checker, int status);
int					ft_memdel_stacks(t_stacks *stacks);
int					ft_error(int err);

unsigned			ft_options(char	*options_ascii);
void				pr_set_options(t_options *m_opions, char **i_av);
int					ft_arg_num_options(char **av, char *name_prog);
int					ft_num_arg_options(char **i_av);

t_boolean			ft_valid(int i_ac, char **i_av, char *i_name_prog);
t_boolean			ft_has_equal(int *i_sort_nbr, int i_size);

void				ft_quick_sort(int *arry, int elements);
int					*ft_get_sort_nbr(t_stack *i_stack);

t_boolean			ft_check_sort(t_stacks *stacks);

/*
** DEBAG
*/
void				ft_print_stacks(t_stacks *stacks);
void				pr_print_commands(t_commands *c, int w, int w2, char *sign);

/*
** FUNCTIONS FOR VISUALIZATION
*/
void				pr_visual(t_checker *checker, int oper_id);
void				pr_put_frame(t_frame *i_frame);
void				pr_put_params_for_visual(t_checker *checker);
void				pr_put_visual_data(t_checker *checker);

#endif
