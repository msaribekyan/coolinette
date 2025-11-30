#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


char	*ft_strupcase(char *str);

typedef struct	s_test
{
	char	*desc;
	char	input[20];
	char	*expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strupcase(\"Hello World!\")",
			.input = "Hello World!",
			.expected = "HELLO WORLD!"
		},
		{
			.desc = "ft_strupcase(\"HellO 1@3$\\n\")",
			.input = "HellO 1@3$\n",
			.expected = "HELLO 1@3$\n"
		},
		{
			.desc = "ft_strupcase(\"_1@!.zdv!24\\x10\\x02\\t\\n\")",
			.input = "_1@!.zdv!24\x10\x02\t\n",
			.expected = "_1@!.ZDV!24\x10\x02\t\n"
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		char *output = ft_strupcase(tests[i].input);
		if (strcmp(output, tests[i].expected) != 0)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"%s"DEFAULT, tests[i].expected);
			printf(CYAN" got "YELLOW"%s\n"DEFAULT, output);
			return (-1);
		}
		i++;
	}
	return (0);	
}
