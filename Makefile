# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 09:05:52 by aelabid           #+#    #+#              #
#    Updated: 2022/03/11 20:15:25 by aelabid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pushswap.c checkargs.c atoi.c collectdata.c pushswap_util.c swap.c push.c\
		lst.c rotate.c reverserotate.c larg_sub.c pushtoB.c pushtoa.c mininhead.c\
		convert.c strjoin.c

OBJ = $(SRC:.c=.o)

#CC_FLAGS = -Wall -Wextra -Werror
CC = cc


NAME = push_swap
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -g  $(OBJ) -o $@
	
%.o: %.c 
	$(CC) -g $(CC_FLAGS) -c $<

clean:
	rm -rf $(OBJ)
		
fclean: clean
	rm -rf $(NAME)

re: fclean all