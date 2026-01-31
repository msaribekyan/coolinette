#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"

#include "libft.h"

typedef struct	s_test
{
	char	*desc;
	char	s[6];
	int	c;
	char	*expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strchr(\"12345\", '3')",
			.s = "12345",
			.c = '3',
			.expected = tests[0].s + 2,
		},
		{
			.desc = "ft_strchr(\"12345\", '1')",
			.s = "12345",
			.c = '1',
			.expected = tests[1].s,
		},
		{
			.desc = "ft_strchr(\"12345\", '\0')",
			.s = "12345",
			.c = '\0',
			.expected = tests[2].s + 5,
		},
		{
			.desc = "ft_strchr(\"12345\", '3' + 256)",
			.s = "12345",
			.c = '3' + 256,
			.expected = tests[3].s + 2,
		},
		{
			.desc = "ft_strchr(\"12341\", '1')",
			.s = "12341",
			.c = '1',
			.expected = tests[4].s,
		},
		{
			.desc = "ft_strchr(\"12341\", '6')",
			.s = "12345",
			.c = '6',
			.expected = 0,
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		char *output = ft_strchr(tests[i].s, tests[i].c);
		if (output != tests[i].expected)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%p"DEFAULT, tests[i].expected);
			printf(CYAN" got "YELLOW"%p\n"DEFAULT, output);
			return (-1);
		}
		i++;
	}
	return (0);	
}
