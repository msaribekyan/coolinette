#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


int	ft_is_prime(int nb);

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
			.desc = "ft_is_prime(-11)",
			.nb = -11,
			.expected = 0,
		},
		{
			.desc = "ft_is_prime(0)",
			.nb = 0,
			.expected = 0,
		},
		{
			.desc = "ft_is_prime(1)",
			.nb = 1,
			.expected = 0,
		},
		{
			.desc = "ft_is_prime(2)",
			.nb = 2,
			.expected = 1,
		},
		{
			.desc = "ft_is_prime(3)",
			.nb = 3,
			.expected = 1,
		},
		{
			.desc = "ft_is_prime(56)",
			.nb = 56,
			.expected = 0,
		},
		{
			.desc = "ft_is_prime(397)",
			.nb = 397,
			.expected = 1,
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		int output = ft_is_prime(tests[i].nb);
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
