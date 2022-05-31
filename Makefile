# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/29 13:45:56 by Youssef           #+#    #+#              #
#    Updated: 2022/05/31 20:07:59 by Youssef          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g

LFLAGS	=	-I includes

LIBFT       =	./libft.a

NAME	=	push_swap

SRCS	=	init_A.c utils_4.c utils_3.c utils_2.c utils_1.c utils_error.c push_swap.c push_swap_low.c main.c


OBJ	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./Libft
	@cp ./Libft/libft.a ./
	@echo "Making Libft..."
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(LIBFT)
	@echo "Making push_swap..."

%.o : %.c	
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ) ./libft.a
	@make -C ./Libft clean
	@echo "Clean(libft)"
	@echo "Clean(push_swap)"

fclean: clean
	@rm -f $(NAME)
	@make -C ./Libft fclean
	@echo "Fclean(libft)"
	@echo "Fclean(push_swap)"

re : fclean all

.PHONY: all fclean clean re $(EXEC)
