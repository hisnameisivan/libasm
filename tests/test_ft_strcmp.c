#include "tests.h"

static void	main_test_ft_strcmp(void)
{
	int		i;
	int		j;

	i = 0;
	while (g_tests[i] != NULL)
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
		printf("first string  : %s$\n", g_tests[i]);
		printf("second string : %s$\n", g_tests[j]);
		printf("strcmp        : %d\n", strcmp(g_tests[i], g_tests[j]));
		printf("ft_strcmp     : %d\n", ft_strcmp(g_tests[i], g_tests[j]));
		assert(strcmp(g_tests[i], g_tests[j]) - ft_strcmp(g_tests[i], g_tests[j]) == 0);
		i++;
	}
}

static void	extra_test_ft_strcmp_1(void)
{
	const char	*first = "привет";	// ""
	const char	*second = "мир";	// "мир"

	printf("extra test strcmp №1\n");
	printf("first string  : %s$\n", first);
	printf("second string : %s$\n", second);
	printf("strcmp        : %d\n", strcmp(first, second));
	printf("ft_strcmp     : %d\n", ft_strcmp(first, second));
	assert(strcmp(first, second) - ft_strcmp(first, second) == 0);
}

static void	extra_test_ft_strcmp_2(void)
{
	const char	*first = "\200";
	const char	*second = "A";

	printf("extra test strcmp №2\n");
	printf("first string  : %s$\n", first);
	printf("second string : %s$\n", second);
	printf("strcmp        : %d\n", strcmp(first, second));
	printf("ft_strcmp     : %d\n", ft_strcmp(first, second));
	assert(strcmp(first, second) - ft_strcmp(first, second) == 0);
}

void		test_ft_strcmp(void)
{
	main_test_ft_strcmp();
	extra_test_ft_strcmp_1();
	extra_test_ft_strcmp_2();
	printf("ft_strcmp: all tests OK\n");
}
