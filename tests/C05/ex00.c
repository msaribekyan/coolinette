#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


int	ft_iterative_factorial(int nb);

typedef struct	s_test
{
	char	*desc;
	int	nb;
	int	expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_iterative_factorial(-10)",
			.nb = -10,
			.expected = 0,
		},
		{
			.desc = "ft_iterative_factorial(0)",
			.nb = 0,
			.expected = 1,
		},
		{
			.desc = "ft_iterative_factorial(1)",
			.nb = 1,
			.expected = 1,
		},
		{
			.desc = "ft_iterative_factorial(2)",
			.nb = 2,
			.expected = 2,
		},
		{
			.desc = "ft_iterative_factorial(12)",
			.nb = 12,
			.expected = 479001600,
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		int output = ft_iterative_factorial(tests[i].nb);
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
