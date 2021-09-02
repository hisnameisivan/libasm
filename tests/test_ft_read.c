#include "tests.h"

static void	main_test_ft_read(void)
{
	int					i;
	char				obuf[BUF_SIZE];
	char				mbuf[BUF_SIZE];
	int					ofd;
	int					mfd;
	int					obr;
	int					mbr;
	int					oer;
	int					mer;
	int					owb;
	int					mwb;

	i = 0;
	ofd = open("ft_read_test_original", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	mfd = open("ft_read_test_my", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	while (g_tests[i] != NULL)
	{
		printf("test read №%d: %s\n", i + 1, g_tests[i]);
		owb = (int)write(ofd, g_tests[i], strlen(g_tests[i]));
		lseek(ofd, -owb, SEEK_CUR);
		errno = 0;
		obr = (int)read(ofd, obuf, BUF_SIZE - 1);
		obuf[obr] = '\0';
		oer = errno;
		printf("original bytes read : %d errno : %d buf : %s\n", obr, oer, obuf);
		mwb = (int)write(mfd, g_tests[i], strlen(g_tests[i]));
		lseek(mfd, -mwb, SEEK_CUR);
		errno = 0;
		mbr = (int)ft_read(mfd, mbuf, BUF_SIZE - 1);
		mbuf[mbr] = '\0';
		mer = errno;
		errno = 0;
		printf("ft_read bytes read  : %d errno : %d buf : %s\n", mbr, mer, mbuf);
		assert((obr - mbr) == 0);
		assert((oer - mer) == 0);
		i++;
	}
	close(ofd);
	close(mfd);
}

static void	extra_test_ft_read_1(void)
{
	const char	*extra_test = "hello world and foo bar";
	char		obuf[BUF_SIZE];
	char		mbuf[BUF_SIZE];
	int			fd;
	int			obr;
	int			mbr;
	int			wb;
	int			osum;
	int			msum;

	printf("extra test read (reading in parts) №1: %s\n", extra_test);
	fd = open("ft_read_test_extra", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	wb = (int)write(fd, extra_test, strlen(extra_test));
	lseek(fd, -wb, SEEK_CUR);
	osum = 0;
	printf("original buf : ");
	while ((obr = read(fd, obuf, 1)) > 0)
	{
		osum += obr;
		printf("%c ", obuf[0]);
	}
	printf("\n");
	close(fd);
	fd = open("ft_read_test_extra", O_RDONLY);
	msum = 0;
	printf("ft_read buf  : ");
	while ((mbr = ft_read(fd, mbuf, 1)) > 0)
	{
		msum += mbr;
		printf("%c ", mbuf[0]);
	}
	printf("\n");
	close(fd);
	assert((osum - msum) == 0);
}

static void	extra_test_ft_read_2(void)
{
	char		obuf[BUF_SIZE];
	char		mbuf[BUF_SIZE];
	int			obr;
	int			mbr;
	int			oer;
	int			mer;

	printf("extra test read (invalid fd) №2\n");
	obr = read(-1, obuf, 1);
	oer = errno;
	printf("original bytes read : %d errno : %d\n", obr, oer);
	errno = 0;
	mbr = ft_read(-1, mbuf, 1);
	mer = errno;
	printf("ft_read bytes read  : %d errno : %d\n", mbr, mer);
	assert((obr - mbr) == 0);
	assert((oer - mer) == 0);
}

void		test_ft_read(void)
{
	main_test_ft_read();
	extra_test_ft_read_1();
	extra_test_ft_read_2();
	printf("ft_read: all tests OK\n");
}
