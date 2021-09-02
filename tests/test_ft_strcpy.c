#include "tests.h"
//add strcmp
static void	main_test_ft_strcpy(void)
{
	int		i;
	char	*buf;

	i = 0;
	while (g_tests[i] != NULL)
	{
		printf("test strcpy №%d\n", i + 1);
		buf = (char *)malloc(sizeof(char) * strlen(g_tests[i]) + 1);
		ft_strcpy(buf, g_tests[i]);
		printf("original  : %s$	len : %u\n", g_tests[i],
			(unsigned int)strlen(g_tests[i]));
		printf("ft_strcpy : %s$	len : %u\n", buf, (unsigned int)strlen(buf));
		assert((int)(strlen(g_tests[i]) - strlen(buf)) == 0);
		free(buf);
		i++;
	}
}

void		test_ft_strcpy(void)
{
	main_test_ft_strcpy();
	printf("ft_strcpy: all tests OK\n");
}
