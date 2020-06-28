# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 10:00:32 by wmaykit           #+#    #+#              #
#    Updated: 2019/10/19 16:24:11 by wmaykit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name ex.outable file for cheker
NAME_CHECKER = checker

# name executable file for push_swap
NAME_PUSH_SWAP = push_swap

# flags
CC = gcc
FLAGS = -Wall -Wextra -Werror

# repo for compiling
GNL_DIR = gnl
SRC_DIR = src
LIBFT_DIR = libft
INCL_DIR = includes
FT_PRINTF_DIR = libftprintf

# sourse file
GNL_FILE = get_next_line.c
LIBFT_FILE = libft.a
INCL_FILE = libftpushswap.h
FT_PRINTF_FILE = libftprintf.a

OBJS_CHECKER = ft_error.o ft_memdel_stacks.o ft_create_new_lst.o \
			  pr_create_sa.o ft_print_stacks.o ft_cut_top_node.o \
			  ft_push.o ft_push_sb.o ft_push_sa.o ft_swap_sa.o ft_swap_sb.o \
			  ft_swap_first_two.o ft_swap_sa_and_sb.o ft_rotate_sa.o \
			  ft_rotate_sb.o ft_rotate_sa_and_sb.o ft_rotate_stack.o \
			  ft_rrotate_sa.o ft_rrotate_sb.o ft_rrotate_sa_and_sb.o \
			  ft_rrotate_stack.o ft_identify_operations.o ft_get_operations.o \
			  ft_set_params.o ft_perform_operations.o ft_check_sort.o \
			  ft_min_value_stack.o ft_max_value_stack.o ft_valid.o \
			  ft_has_equal.o ft_get_sort_nbr.o ft_quick_sort.o \
			  ft_exit_checker.o ft_options.o ft_num_arg_options.o \
			  pr_set_options.o pr_open_file.o pr_visual.o pr_put_frame.o \
			  pr_put_params_for_visual.o ft_is_part.o pr_put_visual_data.o

OBJS_PUSH_SWAP = pr_create_sa.o ft_error.o ft_check_sort.o  ft_push_sb.o\
				 ft_push_sa.o ft_push.o ft_create_new_lst.o \
				 ft_memdel_stacks.o ft_rotate_sa.o ft_rotate_sb.o \
				 ft_rotate_sa_and_sb.o ft_rotate_stack.o ft_rrotate_sa.o \
				 ft_rrotate_sb.o ft_rrotate_sa_and_sb.o ft_rrotate_stack.o \
				 ft_cut_top_node.o ft_quick_sort.o ft_get_sort_nbr.o \
				 ft_is_part.o ft_get_index_value_in_stack.o ft_print_stacks.o \
				 ft_sorting_sa_by_three_parts.o pr_sa_and_add_to_buff.o \
				 pr_sb_and_add_to_buff.o pr_ss_and_add_to_buff.o \
				 pr_pa_and_add_to_buff.o pr_pb_and_add_to_buff.o \
				 pr_ra_and_add_to_buff.o pr_rb_and_add_to_buff.o \
		 		 pr_rr_and_add_to_buff.o pr_rra_and_add_to_buff.o \
				 pr_rrb_and_add_to_buff.o pr_rrr_and_add_to_buff.o \
				 pr_sort_only_three_values_sa.o pr_add_command_to_buff.o \
				 pr_print_buff.o ft_get_size_in_bytes.o ft_end_new_line.o \
				 ft_max_value_stack.o ft_min_value_stack.o ft_swap_sa.o \
				 ft_swap_sb.o ft_swap_first_two.o ft_swap_sa_and_sb.o \
				 pr_sort_stack_and_print_command.o ft_get_low_num_cmd.o \
				 pr_execute_command.o ft_get_best_commands.o \
				 ft_get_insert_index_in_stack.o ft_get_num_lift_up_cmd.o \
				 pr_print_commands.o ft_valid.o ft_has_equal.o \
				 ft_exit_push_swap.o ft_options.o ft_num_arg_options.o \
				 pr_set_options.o pr_open_file.o pr_sort_only_five_values_sa.o

SRC_ALL = ft_error.c ft_memdel_stacks.c ft_create_new_lst.c ft_push.c \
		  pr_create_sa.c ft_print_stacks.c ft_cut_top_node.c \
		  ft_push_sb.c ft_push_sa.c ft_swap_sa.c ft_swap_sb.c \
		  ft_swap_first_two.c ft_swap_sa_and_sb.c ft_rotate_sa.c \
		  ft_rotate_sb.c ft_rotate_sa_and_sb.c ft_rotate_stack.c \
		  ft_rrotate_sa.c ft_rrotate_sb.c ft_rrotate_sa_and_sb.c \
		  ft_rrotate_stack.c ft_identify_operations.c ft_get_operations.c \
		  ft_set_params.c ft_perform_operations.c ft_check_sort.c \
		  ft_quick_sort.c ft_get_sort_nbr.c \
		  ft_get_index_value_in_stack.c ft_is_part.c \
		  ft_sorting_sa_by_three_parts.c pr_sa_and_add_to_buff.c \
		  pr_sb_and_add_to_buff.c pr_ss_and_add_to_buff.c \
		  pr_pa_and_add_to_buff.c pr_pb_and_add_to_buff.c \
		  pr_ra_and_add_to_buff.c pr_rb_and_add_to_buff.c \
		  pr_rr_and_add_to_buff.c pr_rra_and_add_to_buff.c \
		  pr_rrb_and_add_to_buff.c pr_rrr_and_add_to_buff.c \
		  pr_sort_only_three_values_sa.c pr_add_command_to_buff.c \
		  pr_print_buff.c ft_get_size_in_bytes.c ft_end_new_line.c \
		  ft_max_value_stack.c ft_min_value_stack.c	\
		  pr_sort_stack_and_print_command.c ft_get_low_num_cmd.c \
		  pr_execute_command.c ft_get_best_commands.c \
		  ft_get_insert_index_in_stack.c ft_get_num_lift_up_cmd.c \
		  pr_print_commands.c ft_valid.c ft_has_equal.c ft_exit_checker.c \
		  ft_exit_push_swap.c ft_options.c ft_num_arg_options.c \
		  pr_set_options.c pr_open_file.c pr_visual.c pr_put_frame.c \
		  pr_put_params_for_visual.c pr_put_visual_data.c \
		  pr_sort_only_five_values_sa.c



# sourse file with path
GNL = $(addprefix $(GNL_DIR)/, $(GNL_FILE))
INCL = $(addprefix $(INCL_DIR)/, $(INCL_FILE))
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_FILE))
FT_PRINTF = $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_FILE))
OBJ_CHECKER = $(addprefix $(SRC_DIR)/, $(OBJS_CHECKER))
OBJ_PUSH_SWAP = $(addprefix $(SRC_DIR)/, $(OBJS_PUSH_SWAP))
SRCS_ALL = $(addprefix $(SRC_DIR)/, $(SRC_ALL))

# object file all file .c
OBJ_ALL = $(SRCS_ALL:.c=.o)

# main file
MAIN_CHECKER = $(addprefix $(SRC_DIR)/, $(NAME_CHECKER:=.c))
MAIN_PUSH_SWAP = $(addprefix $(SRC_DIR)/, $(NAME_PUSH_SWAP:=.c))

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(NAME_CHECKER): $(OBJ_CHECKER) $(FT_PRINTF) $(MAIN_CHECKER)
	$(CC) $(FLAGS) $(MAIN_CHECKER) $(OBJ_CHECKER) $(FT_PRINTF) $(GNL) \
	-I $(INCL_DIR) -I $(FT_PRINTF_DIR) -I $(FT_PRINTF_DIR)/float -I $(GNL_DIR) \
	-I $(LIBFT_DIR) -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf \
	-o $(NAME_CHECKER)

$(NAME_PUSH_SWAP): $(OBJ_PUSH_SWAP) $(LIBFT) $(FT_PRINTF) $(MAIN_PUSH_SWAP)
	$(CC) $(FLAGS) $(MAIN_PUSH_SWAP) $(OBJ_PUSH_SWAP) $(LIBFT) $(FT_PRINTF) \
		-I $(INCL_DIR) -I $(FT_PRINTF_DIR) -I $(FT_PRINTF_DIR)/float \
		-I $(GNL_DIR) -I $(LIBFT_DIR) -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) \
		-lftprintf -o $(NAME_PUSH_SWAP)

$(OBJ_ALL): %.o: %.c $(INCL) $(LIBFT)
	$(CC) $(FLAGS) -c $< -I $(INCL_DIR) -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) \
		-I $(GNL_DIR) -I $(FT_PRINTF_DIR)/float -o $@

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_ALL)
	make -C $(FT_PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_CHECKER) $(NAME_PUSH_SWAP)
	make -C $(FT_PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY:	all clean fclean re
