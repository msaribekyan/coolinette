#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

typedef struct	s_test
{
	char	*desc;
	char	*nbr;
	char	*base_from;
	char	*base_to;
	char	*expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_convert_base(\"-80000000\", \"0123456789abcdef\", \"0123456789\")",
			.nbr = "80000000",
			.base_from = "0123456789abcdef",
			.base_to = "0123456789",
			.expected = "-2147483648",
		},
		{
			.desc = "ft_convert_base(\"10\", \"010\", \"01\")",
			.nbr = "10",
			.base_from = "010",
			.base_to = "01",
			.expected = 0,
		},
		{
			.desc = "ft_convert_base(\"10\", \"01\", \"010\")",
			.nbr = "10",
			.base_from = "01",
			.base_to = "010",
			.expected = 0,
		},
		{
			.desc = "ft_convert_base(\"10\", \"0 1\", \"01\")",
			.nbr = "10",
			.base_from = "0 1",
			.base_to = "01",
			.expected = 0,
		},
		{
			.desc = "ft_convert_base(\"10\", \"01\", \"0 1\")",
			.nbr = "10",
			.base_from = "01",
			.base_to = "0 1",
			.expected = 0,
		},
		{
			.desc = "ft_convert_base(\"10\", \"0+1\", \"0-1\")",
			.nbr = "10",
			.base_from = "0+1",
			.base_to = "0-1",
			.expected = 0,
		},
		{
			.desc = "ft_convert_base(\"-15\", \"0123456789\", \"0123456789abcdef\")",
			.nbr = "-15",
			.base_from = "0123456789",
			.base_to = "0123456789abcdef",
			.expected = "-f",
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		char *output = ft_convert_base(tests[i].nbr, tests[i].base_from, tests[i].base_to);
		if (tests[i].expected == 0 && output != 0)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%p\n" DEFAULT, tests[i].expected);
			return (-1);
		}
		if (output && strcmp(output, tests[i].expected) != 0)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%s"DEFAULT, tests[i].expected);
			printf(CYAN " got "YELLOW"%s\n"DEFAULT, output);
			return (-1);
		}
		i++;
	}
	return (0);	
}
