/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:37:35 by ivan              #+#    #+#             */
/*   Updated: 2021/08/21 01:53:27 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
// ssize_t	ft_write(int fd, const void* buf, size_t count) {
// 	return write(fd, buf, count);
// }
ssize_t	ft_write(int fd, const void* buf, size_t count);

void	test_strlen(void)
{
	const char*	const	tests[] =
	{
		"hello",
		"foo",
		"bar",
		"",
		"\n",
		"hello world and foo bar",
		NULL
	};
	int					i;

	i = 0;
	while (tests[i] != NULL)
	{
		printf("test strlen №%d: %s\n", i, tests[i]);
		printf("strlen    : %u\n", (unsigned int)strlen(tests[i]));
		printf("ft_strlen : %u\n", (unsigned int)ft_strlen(tests[i]));
		assert((int)(strlen(tests[i]) - ft_strlen(tests[i])) == 0);
		i++;
	}
	printf("ft_strlen: all tests OK\n");
}

void	test_strcpy(void)
{
	const char* const	tests[] =
	{
		"hello",
		"foo",
		"bar",
		"",
		"\n",
		"hello world and foo bar",
		NULL
	};
	char				*buf;
	int					i;

	i = 0;
	while (tests[i] != NULL)
	{
		printf("test strcpy №%d\n", i);
		buf = (char *)malloc(sizeof(char) * strlen(tests[i]) + 1);
		ft_strcpy(buf, tests[i]);
		printf("original  : %s$	len : %u\n", tests[i], (unsigned int)strlen(tests[i]));
		printf("ft_strcpy : %s$	len : %u\n", buf, (unsigned int)strlen(buf));
		assert((int)(strlen(tests[i]) - strlen(buf)) == 0);
		free(buf);
		i++;
	}
	printf("ft_strcpy: all tests OK\n");
}

void	test_strcmp(void)
{
	const char* const	tests[] =
	{
		"hello",
		"foo",
		"bar",
		"",
		"\n",
		"hello world and foo bar",
		NULL
	};
	int					i;
	int					j;

	i = 0;
	while (tests[i] != NULL)
	{
		printf("test strcmp №%d\n", i);
		if (i % 2 != 0)
		{
			j = i - 1;
		}
		else
		{
			j = i;
		}
		printf("first string  : %s\n", tests[i]);
		printf("second string : %s\n", tests[j]);
		printf("strcmp        : %d\n", strcmp(tests[i], tests[j]));
		printf("ft_strcmp     : %d\n", ft_strcmp(tests[i], tests[j]));
		assert(strcmp(tests[i], tests[j]) - ft_strcmp(tests[i], tests[j]) == 0);
		i++;
	}
	printf("extra test strcmp №1\n");
	printf("first string  : %s\n", "привет");
	printf("second string : %s\n", "мир");
	printf("strcmp        : %d\n", strcmp("привет", "мир"));
	printf("ft_strcmp     : %d\n", ft_strcmp("привет", "мир"));
	assert(strcmp("привет", "мир") - ft_strcmp("привет", "мир") == 0);
	printf("extra test strcmp №2\n");
	printf("first string  : %s\n", "\200");
	printf("second string : %s\n", "A");
	printf("strcmp        : %d\n", strcmp("\200", "A"));
	printf("ft_strcmp     : %d\n", ft_strcmp("\200", "A"));
	assert(strcmp("\200", "A") - ft_strcmp("\200", "A") == 0);
	printf("ft_strcmp: all tests OK\n");
}

void	test_write()
{
	const char* const	tests[] =
	{
		"hello",
		"foo",
		"bar",
		"",
		"\n",
		"hello world and foo bar",
		NULL
	};
	const char			*extra_test = "extra";
	int					i;
	int					fd;
	int					owb;
	int					mwb;
	int					oer;
	int					mer;

	i = 0;
	fd = creat("ft_write_test", S_IRWXU);
	while (tests[i] != NULL)
	{
		printf("test write №%d: %s\n", i, tests[i]);
		owb = (int)write(fd, tests[i], strlen(tests[i]));
		oer = errno;
		printf("original written bytes : %d errno: %d\n", owb, errno);
		mwb = (int)ft_write(fd, tests[i], strlen(tests[i]));
		mer = errno;
		printf("ft_write written bytes : %d errno: %d\n", mwb, errno);
		assert((owb - mwb) == 0);
		assert((oer - mer) == 0);
		i++;
	}
	i--;
	printf("extra test write №1: %s\n", tests[i]);
	owb = (int)write(fd, tests[i], strlen(tests[i]) - 1);
	oer = errno;
	printf("original written bytes : %d errno: %d\n", owb, errno);
	mwb = (int)ft_write(fd, tests[i], strlen(tests[i]) - 1);
	mer = errno;
	printf("ft_write written bytes : %d errno: %d\n", mwb, errno);
	assert((owb - mwb) == 0);
	assert((oer - mer) == 0);
	i++;
	printf("extra test (invalid fd) write №2: %s\n", extra_test);
	owb = (int)write(-1, extra_test, strlen(extra_test));
	oer = errno;
	printf("original written bytes : %d errno: %d\n", owb, errno);
	errno = 0;
	mwb = (int)ft_write(-1, extra_test, strlen(extra_test));
	mer = errno;
	printf("ft_write written bytes : %d errno: %d\n", mwb, errno);
	assert((owb - mwb) == 0);
	assert((oer - mer) == 0);
	printf("ft_write: all tests OK\n");
	close(fd);
}

int		main(void)
{
	// test_strlen();
	// test_strcpy();
	// test_strcmp();
	test_write();
	return (0);
}
