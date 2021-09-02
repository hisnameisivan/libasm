#include "tests.h"

static void	main_test_ft_write(void)
{
	int		i;
	int		fd;
	int		owb;
	int		mwb;
	int		oer;
	int		mer;

	i = 0;
	fd = creat("ft_write_test", S_IRWXU);
	while (g_tests[i] != NULL)
	{
		printf("test write №%d: %s\n", i + 1, g_tests[i]);
		owb = (int)write(fd, g_tests[i], strlen(g_tests[i]));
		oer = errno;
		errno = 0;
		printf("original written bytes : %d errno : %d\n", owb, oer);
		mwb = (int)ft_write(fd, g_tests[i], strlen(g_tests[i]));
		mer = errno;
		printf("ft_write written bytes : %d errno : %d\n", mwb, mer);
		assert((owb - mwb) == 0);
		assert((oer - mer) == 0);
		i++;
	}
	close(fd);
}

static void	extra_test_ft_write_1(void)
{
	const char	*extra_test = "extra";
	int			fd;
	int			owb;
	int			oer;
	int			mwb;
	int			mer;

	fd = creat("ft_write_test", S_IRWXU);
	printf("extra test write №1: %s\n", extra_test);
	owb = (int)write(fd, extra_test, strlen(extra_test) - 1);
	oer = errno;
	errno = 0;
	printf("original written bytes : %d errno : %d\n", owb, oer);
	mwb = (int)ft_write(fd, extra_test, strlen(extra_test) - 1);
	mer = errno;
	printf("ft_write written bytes : %d errno : %d\n", mwb, mer);
	assert((owb - mwb) == 0);
	assert((oer - mer) == 0);
	close(fd);
}

static void	extra_test_ft_write_2(void)
{
	const char	*extra_test = "extra";
	int			fd;
	int			owb;
	int			oer;
	int			mwb;
	int			mer;

	fd = creat("ft_write_test", S_IRWXU);
	printf("extra test (invalid fd) write №2: %s\n", extra_test);
	owb = (int)write(-1, extra_test, strlen(extra_test));
	oer = errno;
	errno = 0;
	printf("original written bytes : %d errno : %d\n", owb, oer);
	mwb = (int)ft_write(-1, extra_test, strlen(extra_test));
	mer = errno;
	printf("ft_write written bytes : %d errno : %d\n", mwb, mer);
	assert((owb - mwb) == 0);
	assert((oer - mer) == 0);
	close(fd);
}

void		test_ft_write(void)
{
	main_test_ft_write();
	extra_test_ft_write_1();
	extra_test_ft_write_2();
	printf("ft_write: all tests OK\n");
}
