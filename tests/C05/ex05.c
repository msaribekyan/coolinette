#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


int	ft_sqrt(int nb);

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
			.desc = "ft_sqrt(-2)",
			.nb = -2,
			.expected = 0,
		},
		{
			.desc = "ft_sqrt(0)",
			.nb = 0,
			.expected = 0,
		},
		{
			.desc = "ft_sqrt(1)",
			.nb = 1,
			.expected = 1,
		},
		{
			.desc = "ft_sqrt(2)",
			.nb = 2,
			.expected = 0,
		},
		{
			.desc = "ft_sqrt(4)",
			.nb = 4,
			.expected = 2,
		},
		{
			.desc = "ft_sqrt(15)",
			.nb = 15,
			.expected = 0,
		},
		{
			.desc = "ft_sqrt(289)",
			.nb = 289,
			.expected = 17,
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		int output = ft_sqrt(tests[i].nb);
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
