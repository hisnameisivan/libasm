#include "tests.h"

static void	main_test_ft_read(void)
{
	int		i;
	t_io	original;
	t_io	my;
	int		owb;
	int		mwb;

	i = 0;
	original.fd = open("ft_read_test_original", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	my.fd = open("ft_read_test_my", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	while (g_tests[i] != NULL)
	{
		printf("test read №%d: %s\n", i + 1, g_tests[i]);
		owb = (int)write(original.fd, g_tests[i], strlen(g_tests[i]));
		lseek(original.fd, -owb, SEEK_CUR);
		errno = 0;
		original.bytes = (int)read(original.fd, original.buf, BUF_SIZE - 1);
		original.buf[original.bytes] = '\0';
		original.err = errno;
		printf("original bytes read : %d errno : %d buf : %s\n", original.bytes, original.err, original.buf);
		mwb = (int)write(my.fd, g_tests[i], strlen(g_tests[i]));
		lseek(my.fd, -mwb, SEEK_CUR);
		errno = 0;
		my.bytes = (int)ft_read(my.fd, my.buf, BUF_SIZE - 1);
		my.buf[my.bytes] = '\0';
		my.err = errno;
		errno = 0;
		printf("ft_read bytes read  : %d errno : %d buf : %s\n", my.bytes, my.err, my.buf);
		assert((original.bytes - my.bytes) == 0);
		assert((original.err - my.err) == 0);
		i++;
	}
	close(original.fd);
	close(my.fd);
}

static void	extra_test_ft_read_1(void)
{
	const char	*extra_test = "hello world and foo bar";
	t_io		original;
	t_io		my;
	int			wb;
	int			rb;

	printf("extra test read (reading in parts) №1: %s\n", extra_test);
	original.fd = open("ft_read_test_extra", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	wb = (int)write(original.fd, extra_test, strlen(extra_test));
	lseek(original.fd, -wb, SEEK_CUR);
	original.bytes = 0;
	printf("original buf : ");
	while ((rb = read(original.fd, original.buf, 1)) > 0)
	{
		original.bytes += rb;
		printf("%c ", original.buf[0]);
	}
	printf("\n");
	close(original.fd);
	my.fd = open("ft_read_test_extra", O_RDONLY);
	my.bytes = 0;
	printf("ft_read buf  : ");
	while ((rb = ft_read(my.fd, my.buf, 1)) > 0)
	{
		my.bytes += rb;
		printf("%c ", my.buf[0]);
	}
	printf("\n");
	close(my.fd);
	assert((original.bytes - my.bytes) == 0);
}

static void	extra_test_ft_read_2(void)
{
	t_io		original;
	t_io		my;

	printf("extra test read (invalid fd) №2\n");
	original.bytes = read(-1, original.buf, 1);
	original.err = errno;
	printf("original bytes read : %d errno : %d\n", original.bytes, original.err);
	errno = 0;
	my.bytes = ft_read(-1, my.buf, 1);
	my.err = errno;
	printf("ft_read bytes read  : %d errno : %d\n", my.bytes, my.err);
	assert((original.bytes - my.bytes) == 0);
	assert((original.err - my.err) == 0);
}

void		test_ft_read(void)
{
	main_test_ft_read();
	extra_test_ft_read_1();
	extra_test_ft_read_2();
	printf("ft_read: all tests OK\n");
}
