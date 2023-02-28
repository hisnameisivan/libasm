#include "tests.h"

static void	main_test_ft_strdup()
{
	int		i;
	char	*buf;

	i = 0;
	while (g_tests[i] != NULL)
	{
		printf("test strdup №%d\n", i + 1);
		buf = ft_strdup(g_tests[i]);
		printf("original  : %s$	len : %d\n", g_tests[i], (int)strlen(g_tests[i]));
		printf("ft_strdup : %s$	len : %d\n", buf, (int)strlen(buf));
		assert((int)(strlen(g_tests[i]) - strlen(buf)) == 0);
		free(buf);
		i++;
	}
}

void		test_ft_strdup(void)
{
	main_test_ft_strdup();
	printf("ft_strdup: all tests OK\n");
}
