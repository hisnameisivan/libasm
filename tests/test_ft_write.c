#include "tests.h"

static void	main_test_ft_write(void)
{
	int		i;
	int		fd;
	t_io	original;
	t_io	my;

	i = 0;
	fd = creat("ft_write_test", S_IRWXU);
	while (g_tests[i] != NULL)
	{
		printf("test write №%d: %s\n", i + 1, g_tests[i]);
		original.bytes = (int)write(fd, g_tests[i], strlen(g_tests[i]));
		original.err = errno;
		errno = 0;
		printf("original written bytes : %d errno : %d\n", original.bytes, original.err);
		my.bytes = (int)ft_write(fd, g_tests[i], strlen(g_tests[i]));
		my.err = errno;
		printf("ft_write written bytes : %d errno : %d\n", my.bytes, my.err);
		assert((original.bytes - my.bytes) == 0);
		assert((original.err - my.err) == 0);
		i++;
	}
	close(fd);
}

static void	extra_test_ft_write_1(void)
{
	const char	*extra_test = "extra";
	int			fd;
	t_io		original;
	t_io		my;

	fd = creat("ft_write_test", S_IRWXU);
	printf("extra test write №1: %s\n", extra_test);
	original.bytes = (int)write(fd, extra_test, strlen(extra_test) - 1);
	original.err = errno;
	errno = 0;
	printf("original written bytes : %d errno : %d\n", original.bytes, original.err);
	my.bytes = (int)ft_write(fd, extra_test, strlen(extra_test) - 1);
	my.err = errno;
	printf("ft_write written bytes : %d errno : %d\n", my.bytes, my.err);
	assert((original.bytes - my.bytes) == 0);
	assert((original.err - my.err) == 0);
	close(fd);
}

static void	extra_test_ft_write_2(void)
{
	const char	*extra_test = "extra";
	int			fd;
	t_io		original;
	t_io		my;

	fd = creat("ft_write_test", S_IRWXU);
	printf("extra test (invalid fd) write №2: %s\n", extra_test);
	original.bytes = (int)write(-1, extra_test, strlen(extra_test));
	original.err = errno;
	errno = 0;
	printf("original written bytes : %d errno : %d\n", original.bytes, original.err);
	my.bytes = (int)ft_write(-1, extra_test, strlen(extra_test));
	my.err = errno;
	printf("ft_write written bytes : %d errno : %d\n", my.bytes, my.err);
	assert((original.bytes - my.bytes) == 0);
	assert((original.err - my.err) == 0);
	close(fd);
}

void		test_ft_write(void)
{
	main_test_ft_write();
	extra_test_ft_write_1();
	extra_test_ft_write_2();
	printf("ft_write: all tests OK\n");
}
