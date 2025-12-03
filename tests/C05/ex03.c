#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


int	ft_recursive_power(int nb, int power);

typedef struct	s_test
{
	char	*desc;
	int	nb;
	int	power;
	int	expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_recursive_power(0, 0)",
			.nb = 0,
			.power = 0,
			.expected = 1,
		},
		{
			.desc = "ft_recursive_power(1, 0)",
			.nb = 1,
			.power = 0,
			.expected = 1,
		},
		{
			.desc = "ft_recursive_power(0, 1)",
			.nb = 0,
			.power = 1,
			.expected = 0,
		},
		{
			.desc = "ft_recursive_power(3, -2)",
			.nb = 3,
			.power = -2,
			.expected = 0,
		},
		{
			.desc = "ft_recursive_power(-2, 3)",
			.nb = -2,
			.power = 3,
			.expected = -8,
		},
		{
			.desc = "ft_recursive_power(13, 4)",
			.nb = 13,
			.power = 4,
			.expected = 28561,
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		int output = ft_recursive_power(tests[i].nb, tests[i].power);
		if (output != tests[i].expected)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%d"DEFAULT, tests[i].expected);
			printf(CYAN" got "YELLOW"%d\n"DEFAULT, output);
			return (-1);
		}
		i++;
	}
	return (0);	
}
