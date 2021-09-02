#ifndef TESTS_H
# define TESTS_H

# include <assert.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>

# include "libasm.h"

# define BUF_SIZE	8

static const char* const	g_tests[] =
{
	"hello",
	"foo",
	"bar",
	"",
	"\n",
	"hello world and foo bar",
	NULL
};

void	test_ft_strlen(void);
void	test_ft_strcpy(void);
void	test_ft_strcmp(void);
void	test_ft_write(void);
void	test_ft_read(void);
void	test_ft_strdup(void);

#endif
