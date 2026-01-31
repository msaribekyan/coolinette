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
	char	*str;
	size_t	expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strlen(\"\")",
			.str = "",
			.expected = 0
		},
		{
			.desc = "ft_strlen(\"Hello World!\")",
			.str = "Hello World!",
			.expected = 12
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		size_t output = ft_strlen(tests[i].str);
		if (output != tests[i].expected)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%ld"DEFAULT, tests[i].expected);
			printf(CYAN" got "YELLOW"%ld\n"DEFAULT, output);
			return (-1);
		}
		i++;
	}
	return (0);	
}
