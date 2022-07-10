# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shan <shan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 01:35:05 by shan              #+#    #+#              #
#    Updated: 2022/07/11 01:42:08 by shan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= push_swap.c\
		  ft_atoi.c\
		  ft_isdigit.c\
		  ft_split.c\
		  ft_strjoin.c\
		  ft_calloc.c\
		  ft_bzero.c\
		  ft_strlcat.c\
		  ft_strlcpy.c\
		  ft_strlen.c\
		  get_next_line.c\
		  sort_small.c\
		  sort_small2.c\
		  longest_increasing.c\
		  utils.c\
		  utils2.c\
		  utils3.c\
		  args.c

OBJS 	= &(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o		: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(M_OBJS) $(M_OBJB)

fclean: clean
		rm -rf $(NAME) $(CHECKER)

re: fclean all
