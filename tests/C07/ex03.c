#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"


char	*ft_strjoin(int size, char **strs, char *sep);

typedef struct	s_test
{
	char	*desc;
	int	size;
	char	*strs[10];
	char	*sep;
	char	*expected;
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_strjoin( 4, {\"hello\", \"world\", \"it's\", \"me\"}, \"~/~\")",
			.size = 4,
			.strs = {"hello", "world", "it's", "me"},
			.sep = "~/~",
			.expected = "hello~/~world~/~it's~/~me",
		},
		{
			.desc = "ft_strjoin( 4, {\"hello\", \"world\", \"it's\", \"me\"}, \"\")",
			.size = 4,
			.strs = {"hello", "world", "it's", "me"},
			.sep = "",
			.expected = "helloworldit'sme",
		},
		{
			.desc = "ft_strjoin(0, {}, \"-\")",
			.size = 0,
			.strs = {},
			.sep = "-",
			.expected = "",
		},
		{
			.desc = "ft_strjoin(1, {\"hello\"}, \"-\")",
			.size = 1,
			.strs = {"hello"},
			.sep = "-",
			.expected = "hello",
		},
		{
			.desc = "ft_strjoin(1, {\"hello\"}, \"\")",
			.size = 1,
			.strs = {"hello"},
			.sep = "",
			.expected = "hello",
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		char *output = ft_strjoin(tests[i].size, tests[i].strs, tests[i].sep);
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
