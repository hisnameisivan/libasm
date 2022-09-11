# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 02:31:28 by ivan              #+#    #+#              #
#    Updated: 2021/09/02 10:25:49 by ivan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

KERNEL = $(shell uname -s)

ifeq ($(KERNEL),Linux)
	ASMFLAGS	= -f elf64
	ASMDIR		= linux/
endif
ifeq ($(KERNEL),Darwin)
	ASMFLAGS	= -f macho64
	ASMDIR		= darwin/
endif

NAME		= libasm.a
ASM			= nasm
CC			= clang
CCFLAGS		= -Wall -Wextra -Werror

ASMSRC		= ft_strlen.s\
			  ft_strcpy.s\
			  ft_strcmp.s\
			  ft_write.s\
			  ft_read.s\
			  ft_strdup.s

TESTNAME	= test_libasm

TESTDIR		= tests/
TESTSRC		= main.c\
			  test_ft_strlen.c\
			  test_ft_strcpy.c\
			  test_ft_strcmp.c\
			  test_ft_write.c\
			  test_ft_read.c\
			  test_ft_strdup.c
HEADERS		= headers/

ASMS		= $(addprefix $(ASMDIR), $(ASMSRC))
ASMOBJ		= $(ASMS:%.s=%.o)
TESTS		= $(addprefix $(TESTDIR), $(TESTSRC))
TESTOBJ		= $(TESTS:%.c=%.o)

all: $(NAME)

./$(ASMDIR)%.o: ./$(ASMDIR)%.s
	$(ASM) $(ASMFLAGS) $<

$(NAME): $(ASMOBJ)
	ar rc $(NAME) $?

clean:
	rm -f $(ASMOBJ) $(TESTOBJ)

fclean: clean
	rm -f $(NAME) $(TESTNAME)
	rm -f ft_write_test
	rm -f ft_read_test_extra
	rm -f ft_read_test_my
	rm -f ft_read_test_original

re: fclean all

test: $(TESTNAME)

test-run: test
	./$(TESTNAME)

./$(TESTDIR)%.o: ./$(TESTDIR)%.c
	$(CC) $(CCFLAGS) -c -I./$(TESTDIR)$(HEADERS) $< -o $@

$(TESTNAME): $(TESTOBJ) $(NAME)
	$(CC) $(CCFLAGS) $(TESTOBJ) $(NAME) -o $(TESTNAME)

.PHONY: all clean fclean re test test-run
