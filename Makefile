# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 01:35:05 by shan              #+#    #+#              #
#    Updated: 2022/07/18 03:12:09 by shan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
BONUS	=	checker

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	push_swap.c\
			error.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_long_atoi.c\
			index.c\
			init_stack.c\
			print_command.c\
			push.c\
			reverse_rotate.c\
			rotate.c\
			sort_big_nb.c\
			sort_small_nb.c\
			sort.c\
			swap.c\
			utils.c\

SRCS_B	=	push_swap_bonus.c\
			error.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_long_atoi.c\
			index.c\
			init_stack.c\
			print_command.c\
			push.c\
			reverse_rotate.c\
			rotate.c\
			sort_big_nb.c\
			sort_small_nb.c\
			sort.c\
			swap.c\
			utils.c\
			gnl.c\
			gnl_utils.c\
			push_bonus.c\
			swap_bonus.c\
			reverse_bonus.c\
			rotate_bonus.c

OBJS 	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o		: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus	: $(BONUS)

$(BONUS): $(OBJS_B)
	$(CC) $(CFLAGS) $^ -o $@

%.o		: %.c push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS) $(OBJS_B)

fclean: clean
		rm -rf $(NAME) $(BONUS)

re: fclean all
