#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


int	ft_atoi(char *str);

typedef struct	s_test
{
	char	*desc;
	char	*str;
	int	expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_atoi(\"   ---+--+1234ab567\")",
			.str = "   ---+--+1234ab567",
			.expected = -1234
		},
		{
			.desc = "ft_atoi(\"-2147483648\")",
			.str = "-2147483648",
			.expected = -2147483648
		},
		{
			.desc = "ft_atoi(\"\")",
			.str = "",
			.expected = 0
		},
		{
			.desc = "ft_atoi(\"\\r\\n\\t\\v\\f -10\")",
			.str = "\r\n\t\v\f -10",
			.expected = -10
		},
		{
			.desc = "ft_atoi(\"-++-a10\")",
			.str = "-++-a10",
			.expected = 0
		},
		{
			.desc = "ft_atoi(\"--12352\")",
			.str = "--12352",
			.expected = 12352
		},
		{
			.desc = "ft_atoi(\"-0\")",
			.str = "-0",
			.expected = 0
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		int output = ft_atoi(tests[i].str);
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
