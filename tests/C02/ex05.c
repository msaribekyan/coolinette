#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"

int	ft_str_is_uppercase(char *str);

typedef struct	s_test
{
	char		*desc;
	char		*input;
	int		expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_str_is_uppercase(\"\")",
			.input = "",
			.expected = 1
		},
		{
			.desc = "ft_str_is_uppercase(\"ABCDEFG\")",
			.input = "ABCDEFG",
			.expected = 1
		},
		{
			.desc = "ft_str_is_uppercase(\"-12:<=?\")",
			.input = "-12:<=?",
			.expected = 0
		},
		{
			.desc = "ft_str_is_uppercase(\"helloworld\")",
			.input = "helloworld",
			.expected = 0
		},
		{
			.desc = "ft_str_is_uppercase(\"HELLO\\n\")",
			.input = "HELLO\n",
			.expected = 0
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		int output = ft_str_is_uppercase(tests[i].input);
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
