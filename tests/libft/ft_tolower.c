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
	char	expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_tolower(\'0\')",
			.c = '0',
			.expected = '0',
		},
		{
			.desc = "ft_tolower(\'9\')",
			.c = '9',
			.expected = '9',
		},
		{
			.desc = "ft_tolower(\'\\0\')",
			.c = '\0',
			.expected = '\0',
		},
		{
			.desc = "ft_tolower(\' \')",
			.c = ' ',
			.expected = ' ',
		},
		{
			.desc = "ft_tolower(\'\\n\')",
			.c = '\n',
			.expected = '\n',
		},
		{
			.desc = "ft_tolower(\'a\')",
			.c = 'a',
			.expected = 'a',
		},
		{
			.desc = "ft_tolower(\'z\')",
			.c = 'z',
			.expected = 'z',
		},
		{
			.desc = "ft_tolower(\'A\')",
			.c = 'A',
			.expected = 'a',
		},
		{
			.desc = "ft_tolower(\'Z\')",
			.c = 'Z',
			.expected = 'z',
		},
		{
			.desc = "ft_tolower(\'\\x7F\')",
			.c = '\x7F',
			.expected = '\x7F',
		},
		{
			.desc = "ft_tolower(\'\\x85\')",
			.c = '\x85',
			.expected = '\x85',
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		char output = ft_tolower(tests[i].c);
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
