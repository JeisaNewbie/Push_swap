# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 11:38:22 by jhwang2           #+#    #+#              #
#    Updated: 2023/01/29 00:12:24 by jhwang2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP		=	push_swap
CHECKER			=	checker
NAME			=	$(PUSH_SWAP) $(CHECKER)
HEADER_DIR		=	./includes/
SHARE_SRC		=	init.c check_error.c struct.c free.c ft_atoi.c\
					list1.c list2.c command1.c command2.c command3.c\
					init_input.c ft_split.c get_next_line.c get_next_line_utils.c
PUSH_SWAP_SRC	=	push_swap.c data_in_five.c data_in_four1.c data_in_four2.c \
					data_in_three.c init_asc_five.c init_asc_or_des_five.c\
					init_des_five.c init_four.c position_utils.c\
					recursion_utils.c simple_sort1.c simple_sort2.c\
					simple_sort3.c simple_sort4.c sort_rest_five.c\
					sort_rest_three_or_four1.c sort_rest_three_or_four2.c\
					sort_utils.c 
CHECKER_SRC		=	checker.c
SHARE_OBJ		=	$(SHARE_SRC:.c=.o)
PUSH_SWAP_OBJ	=	$(PUSH_SWAP_SRC:.c=.o)
CHECKER_OBJ		=	$(CHECKER_SRC:.c=.o)
OBJ				=	$(SHARE_OBJ) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)

CFLAGS			=	-Wall -Wextra -Werror
CC				=	CC

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $@ -c $<

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $(PUSH_SWAP) $(PUSH_SWAP_OBJ) $(SHARE_OBJ)
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -o $(CHECKER) $(CHECKER_OBJ) $(SHARE_OBJ)

clean:
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re:
	make fclean
	make all

.PHONY	:	all clean fclean re