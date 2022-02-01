# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acretu <acretu@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 11:54:28 by acretu            #+#    #+#              #
#    Updated: 2022/01/26 13:23:48 by acretu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar -rcsv
RM		= 	rm -f

NAME	= 	push_swap


STD		= 	ft_atoi.c \
			ft_check_input.c \
			ft_check_int.c \
			ft_init_stack.c \
			ft_initial_check.c \
			sorting_utils.c \
			sorting_in_order.c \
			ft_second_check.c \
			ft_small_sort.c \
			lists_utils.c \
			main.c \
			moves_utils_b.c \
			moves_utils_a.c \
			ft_large_sort.c \
			large_sort_utils_one.c \
			large_sort_utils_two.c \
			large_sort_utils_three.c \
			large_sort_utils_four.c \
			small_sort_utils.c
			
OBJ		= 	${STD:.c=.o}
			

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean: 
			$(RM) $(OBJ) $(BON_OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re