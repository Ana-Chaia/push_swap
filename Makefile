# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 16:59:42 by anacaro5          #+#    #+#              #
#    Updated: 2024/07/02 17:42:40 by anacaro5         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_M          = push_swap
#NAME_B         = push_swap_bonus


CC              = cc
CFLAGS          = -Werror -Wall -Wextra -g3
#LIBFT          = ./libplus/libft.a

M_INC           = -I Mandatory/push_swap.h
#B_INC          = -I bonus/push_swap_bonus.h

PATH_M          =  Mandatory/
C_FILES_M       =  $(addprefix $(PATH_M), check_av.c check_costs.c init_infos.c init_stack.c main.c push_swap.c work_moves.c push.c reverse_rotate.c rotate.c swap.c utils.c)

#PATH_B         =  bonus/
#C_FILES_B      =  $(addprefix $(PATH_B), .c)


C_FILES_M_O     =  $(C_FILES_M:%.c=%.o)


#C_FILES_B_O    =  $(CLIENT_B:%.c=%.o)


BLUE            = \033[1;36m
WHITE           = \033[0;39m


all: $(NAME_M)

$(NAME_M): $(C_FILES_M_O)
		$(CC) $(CFLAGS) $^ -I $(PATH_M) -o $@

#bonus: $(NAME_B)

#$(NAME_B): $(C_FILES_B_O)
# $(CC) $(CFLAGS) $< -I $(PATH_B) -o $@

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(C_FILES_M_O) 
# $(C_FILES_B_O)

fclean: clean
		rm -f $(NAME_M) 
#$(NAME_B)

re: fclean all

.PHONY: all clean fclean re
