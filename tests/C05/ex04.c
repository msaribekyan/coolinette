#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


int	ft_fibonacci(int index);

typedef struct	s_test
{
	char	*desc;
	int	index;
	int	expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_fibonacci(0)",
			.index = 0,
			.expected = 0,
		},
		{
			.desc = "ft_fibonacci(-2)",
			.index = -2,
			.expected = -1,
		},
		{
			.desc = "ft_fibonacci(1)",
			.index = 1,
			.expected = 1,
		},
		{
			.desc = "ft_fibonacci(2)",
			.index = 2,
			.expected = 1,
		},
		{
			.desc = "ft_fibonacci(15)",
			.index = 15,
			.expected = 610,
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		int output = ft_fibonacci(tests[i].index);
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
