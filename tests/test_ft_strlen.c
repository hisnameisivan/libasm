#include "tests.h"

static void	main_test_ft_strlen(void)
{
	int		i;

	i = 0;
	while (g_tests[i] != NULL)
	{
		printf("test strlen №%d: %s\n", i + 1, g_tests[i]);
		printf("strlen    : %d\n", (int)strlen(g_tests[i]));
		printf("ft_strlen : %d\n", (int)ft_strlen(g_tests[i]));
		assert((int)(strlen(g_tests[i]) - ft_strlen(g_tests[i])) == 0);
		i++;
	}
}

void		test_ft_strlen(void)
{
	main_test_ft_strlen();
	printf("ft_strlen: all tests OK\n");
}
