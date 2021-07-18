# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 02:31:28 by ivan              #+#    #+#              #
#    Updated: 2021/07/18 18:39:42 by ivan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
ASM			= nasm
ASMFLAGS	= -f elf64
ASMSRC		= ft_strlen.s

TESTNAME	= test_libasm
CC			= clang
CCFLAGS		= -Wall -Wextra -Werror
MAIN		= main.c

ASMOBJ	= $(ASMSRC:%.s=%.o)
MAINOBJ	= $(MAIN:%.c=%.o)

all: $(NAME)

$(ASMOBJ): $(ASMSRC)
	$(ASM) $(ASMFLAGS) $(ASMSRC)

$(NAME): $(ASMOBJ)
	ar rc $(NAME) $?

clean:
	rm -f $(ASMOBJ) $(MAINOBJ)

fclean: clean
	rm -f $(NAME) $(TESTNAME)

re: fclean all

# bonus:

test: $(TESTNAME) # $(NAME)

$(MAINOBJ): $(MAIN)
	$(CC) $(CCFLAGS) -c $< -o $@

$(TESTNAME): $(MAINOBJ) # $(ASMOBJ)
	$(CC) $(CCFLAGS) $< $(NAME) -o $(TESTNAME)

.PHONY: all clean fclean re bonus test
