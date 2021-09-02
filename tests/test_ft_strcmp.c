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
		printf("first string  : %s\n", g_tests[i]);
		printf("second string : %s\n", g_tests[j]);
		printf("strcmp        : %d\n", strcmp(g_tests[i], g_tests[j]));
		printf("ft_strcmp     : %d\n", ft_strcmp(g_tests[i], g_tests[j]));
		assert(strcmp(g_tests[i], g_tests[j]) - ft_strcmp(g_tests[i],
			g_tests[j]) == 0);
		i++;
	}
}

static void	extra_test_ft_strcmp_1(void)
{
	printf("extra test strcmp №1\n");
	printf("first string  : %s\n", "привет");
	printf("second string : %s\n", "мир");
	printf("strcmp        : %d\n", strcmp("привет", "мир"));
	printf("ft_strcmp     : %d\n", ft_strcmp("привет", "мир"));
	assert(strcmp("привет", "мир") - ft_strcmp("привет", "мир") == 0);
}

static void	extra_test_ft_strcmp_2(void)
{
	printf("extra test strcmp №2\n");
	printf("first string  : %s\n", "\200");
	printf("second string : %s\n", "A");
	printf("strcmp        : %d\n", strcmp("\200", "A"));
	printf("ft_strcmp     : %d\n", ft_strcmp("\200", "A"));
	assert(strcmp("\200", "A") - ft_strcmp("\200", "A") == 0);
}

void		test_ft_strcmp(void)
{
	main_test_ft_strcmp();
	extra_test_ft_strcmp_1();
	extra_test_ft_strcmp_2();
	printf("ft_strcmp: all tests OK\n");
}
