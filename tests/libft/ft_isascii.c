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
	char	c;
	int	expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_isascii(\'0\')",
			.c = '0',
			.expected = 1,
		},
		{
			.desc = "ft_isascii(\'9\')",
			.c = '9',
			.expected = 1,
		},
		{
			.desc = "ft_isascii(\'\\0\')",
			.c = '\0',
			.expected = 1,
		},
		{
			.desc = "ft_isascii(\' \')",
			.c = ' ',
			.expected = 1,
		},
		{
			.desc = "ft_isascii(\'\\n\')",
			.c = '\n',
			.expected = 1,
		},
		{
			.desc = "ft_isascii(\'a\')",
			.c = 'a',
			.expected = 1,
		},
		{
			.desc = "ft_isascii(\'z\')",
			.c = 'z',
			.expected = 1,
		},
		{
			.desc = "ft_isascii(\'A\')",
			.c = 'A',
			.expected = 1,
		},
		{
			.desc = "ft_isascii(\'Z\')",
			.c = 'Z',
			.expected = 1,
		},
		{
			.desc = "ft_isascii(\'\\x7F\')",
			.c = '\x7F',
			.expected = 1,
		},
		{
			.desc = "ft_isascii(\'\\x85\')",
			.c = '\x85',
			.expected = 0,
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		int output = ft_isascii(tests[i].c);
		if (output != tests[i].expected)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%d "DEFAULT, tests[i].expected);
			printf(CYAN "got "YELLOW"%d\n"DEFAULT, output);
			return (-1);
		}
		i++;
	}
	return (0);	
}
