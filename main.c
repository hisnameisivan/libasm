/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:37:35 by ivan              #+#    #+#             */
/*   Updated: 2021/08/24 23:13:35 by ivan             ###   ########.fr       */
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
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, const void* buf, size_t count);
char	*ft_strdup(const char *s) {
	return strdup(s);
}
// char	*ft_strdup(const char *s);

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
		printf("test strlen №%d: %s\n", i + 1, tests[i]);
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
		printf("test strcpy №%d\n", i + 1);
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
		printf("test strcmp №%d\n", i + 1);
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
		printf("test write №%d: %s\n", i + 1, tests[i]);
		owb = (int)write(fd, tests[i], strlen(tests[i]));
		oer = errno;
		printf("original written bytes : %d errno : %d\n", owb, errno);
		mwb = (int)ft_write(fd, tests[i], strlen(tests[i]));
		mer = errno;
		printf("ft_write written bytes : %d errno : %d\n", mwb, errno);
		assert((owb - mwb) == 0);
		assert((oer - mer) == 0);
		i++;
	}
	i--;
	printf("extra test write №1: %s\n", tests[i]);
	owb = (int)write(fd, tests[i], strlen(tests[i]) - 1);
	oer = errno;
	printf("original written bytes : %d errno : %d\n", owb, errno);
	mwb = (int)ft_write(fd, tests[i], strlen(tests[i]) - 1);
	mer = errno;
	printf("ft_write written bytes : %d errno : %d\n", mwb, errno);
	assert((owb - mwb) == 0);
	assert((oer - mer) == 0);
	printf("extra test (invalid fd) write №2: %s\n", extra_test);
	owb = (int)write(-1, extra_test, strlen(extra_test));
	oer = errno;
	printf("original written bytes : %d errno : %d\n", owb, errno);
	errno = 0;
	mwb = (int)ft_write(-1, extra_test, strlen(extra_test));
	mer = errno;
	printf("ft_write written bytes : %d errno : %d\n", mwb, errno);
	assert((owb - mwb) == 0);
	assert((oer - mer) == 0);
	printf("ft_write: all tests OK\n");
	close(fd);
}

#define BUF_SIZE	8

void	test_read()
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
	char				obuf[BUF_SIZE];
	char				mbuf[BUF_SIZE];
	int					ofd;
	int					mfd;
	int					efd;
	int					obr;
	int					mbr;
	int					oer;
	int					mer;
	int					owb;
	int					mwb;
	int					osum;
	int					msum;

	i = 0;
	ofd = open("ft_read_test_original", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	mfd = open("ft_read_test_my", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	while (tests[i] != NULL)
	{
		printf("test read №%d: %s\n", i + 1, tests[i]);
		owb = (int)write(ofd, tests[i], strlen(tests[i]));
		errno = 0;
		lseek(ofd, -owb, SEEK_CUR);
		obr = (int)read(ofd, obuf, BUF_SIZE - 1);
		obuf[obr] = '\0';
		oer = errno;
		printf("original bytes read : %d errno : %d buf : %s\n", obr, errno, obuf);
		mwb = (int)write(mfd, tests[i], strlen(tests[i]));
		errno = 0;
		lseek(mfd, -mwb, SEEK_CUR);
		mbr = (int)ft_read(mfd, mbuf, BUF_SIZE - 1);
		mbuf[mbr] = '\0';
		mer = errno;
		printf("ft_read bytes read  : %d errno : %d buf : %s\n", mbr, errno, mbuf);
		assert((obr - mbr) == 0);
		assert((oer - mer) == 0);
		i++;
	}
	close(ofd);
	close(mfd);
	i--;
	printf("extra test read (reading in parts) №1: %s\n", tests[i]);
	efd = open("ft_read_test_extra", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	owb = (int)write(efd, tests[i], strlen(tests[i]));
	lseek(ofd, -owb, SEEK_CUR);
	osum = 0;
	printf("original buf : ");
	while ((obr = read(efd, obuf, 1)) > 0)
	{
		osum += obr;
		printf("%c ", obuf[0]);
	}
	printf("\n");
	close(efd);
	efd = open("ft_read_test_extra", O_RDONLY);
	msum = 0;
	printf("ft_read buf  : ");
	while ((mbr = ft_read(efd, mbuf, 1)) > 0)
	{
		msum += mbr;
		printf("%c ", mbuf[0]);
	}
	printf("\n");
	close(efd);
	assert((osum - msum) == 0);
	printf("extra test read (invalid fd) №2: %s\n", tests[i]);
	obr = read(-1, obuf, 1);
	oer = errno;
	printf("original bytes read : %d errno : %d\n", obr, errno);
	errno = 0;
	mbr = ft_read(-1, mbuf, 1);
	mer = errno;
	printf("ft_read bytes read  : %d errno : %d\n", mbr, errno);
	assert((obr - mbr) == 0);
	assert((oer - mer) == 0);
	printf("ft_read: all tests OK\n");
}

void	test_strdup()
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
	char				*buf;

	i = 0;
	while (tests[i] != NULL)
	{
		printf("test strdup №%d\n", i + 1);
		buf = ft_strdup(tests[i]);
		printf("original  : %s$	len : %u\n", tests[i], (unsigned int)strlen(tests[i]));
		printf("ft_strdup : %s$	len : %u\n", buf, (unsigned int)strlen(buf));
		free(buf);
		i++;
	}
	printf("ft_strcpy: all tests OK\n");
}

int		main(void)
{
	// test_strlen();
	// test_strcpy();
	// test_strcmp();
	// test_write();
	// test_read();
	test_strdup();
	return (0);
}
