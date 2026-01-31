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
	char		*desc;
	unsigned char	s[5];
	size_t		n;
	int		c;
	unsigned char	expected[5];
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_memset(\"{0, 0, 0, 0, 0}, 42, 5\")",
			.s = {0, 0, 0, 0, 0},
			.n = 5,
			.c = 42,
			.expected = {42, 42, 42, 42, 42},
		},
		{
			.desc = "ft_memset(\"{0, 0, 0, 0, 0}, 261, 5\")",
			.s = {0, 0, 0, 0, 0},
			.n = 5,
			.c = 261,
			.expected = {5, 5, 5, 5, 5},
		},
		{
			.desc = "ft_memset(\"{0, 0, 0, 0, 0}, 42, 3\")",
			.s = {0, 0, 0, 0, 0},
			.n = 3,
			.c = 42,
			.expected = {42, 42, 42, 0, 0},
		},
		{
			.desc = "ft_memset(\"{0, 0, 0, 0, 0}, 42, 0\")",
			.s = {0, 0, 0, 0, 0},
			.n = 0,
			.c = 42,
			.expected = {0, 0, 0, 0, 0},
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		unsigned char *output = (unsigned char *) ft_memset((void *) tests[i].s, tests[i].c, tests[i].n);
		if (memcmp(output, tests[i].expected, 5) != 0)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"{%d, %d, %d, %d, %d}"DEFAULT, tests[i].expected[0], tests[i].expected[1], tests[i].expected[2], tests[i].expected[3], tests[i].expected[4]);
			printf(CYAN" got "YELLOW"{%d, %d, %d, %d, %d}\n"DEFAULT, output[0], output[1], output[2], output[3], output[4]);
			return (-1);
		}
		i++;
	}
	return (0);	
}
