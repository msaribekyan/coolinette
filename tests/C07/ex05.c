#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


char	**ft_split(char *str, char *charset);

typedef struct	s_test
{
	char	*desc;
	char	*str;
	char	*charset;
	int	size;
	char	*expected[20];
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_split(\"Hello,World\", \",\")",
			.str = "Hello,World",
			.charset = ",",
			.size = 3,
			.expected = {"Hello", "World", 0},
		},
		{
			.desc = "ft_split(\"Hello,World, and   that's   it\", \", \")",
			.str = "Hello,World, and   that's   it",
			.charset = ", ",
			.size = 6,
			.expected = {"Hello", "World", "and", "that's", "it", 0},
		},
		{
			.desc = "ft_split(\"Hello\", \",\")",
			.str = "Hello",
			.charset = ",",
			.size = 2,
			.expected = {"Hello", 0},
		},
		{
			.desc = "ft_split(\"\", \",\")",
			.str = "",
			.charset = "",
			.size = 1,
			.expected = {0},
		},
		{
			.desc = "ft_split(\",\", \",\")",
			.str = ",",
			.charset = ",",
			.size = 1,
			.expected = {0},
		},
		{
			.desc = "ft_split(\",Hello\", \",\")",
			.str = ",Hello",
			.charset = ",",
			.size = 2,
			.expected = {"Hello", 0},
		},
		{
			.desc = "ft_split(\",Hello,\", \",\")",
			.str = ",Hello,",
			.charset = ",",
			.size = 2,
			.expected = {"Hello", 0},
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		char **output = ft_split(tests[i].str, tests[i].charset);
		int j = 0;
		while(j < tests[i].size)
		{
			if (tests[i].expected[j] == 0 && output[j] != 0)
			{
				printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
				printf(CYAN "Expected "YELLOW"%p " DEFAULT, tests[i].expected[j]);
				printf(CYAN "got "YELLOW"%p\n"DEFAULT, output[j]);
				return (-1);
		}
			if (output[j] && strcmp(output[j], tests[i].expected[j]) != 0)
			{
				printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
				printf(CYAN "Expected "YELLOW"%s "DEFAULT, tests[i].expected[j]);
				printf(CYAN "got "YELLOW"%s\n"DEFAULT, output[j]);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);	
}
