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
	unsigned char	expected[5];
}	t_test;

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_bzero(\"{1, 2, 3, 4, 5}, 5\")",
			.s = {1, 2, 3, 4, 5},
			.n = 5,
			.expected = {0, 0, 0, 0, 0},
		},
		{
			.desc = "ft_bzero(\"{1, 2, 3, 4, 5}, 3\")",
			.s = {1, 2, 3, 4, 5},
			.n = 3,
			.expected = {0, 0, 0, 4, 5},
		},
		{
			.desc = "ft_bzero(\"{1, 2, 3, 4, 5}, 0\")",
			.s = {1, 2, 3, 4, 5},
			.n = 0,
			.expected = {1, 2, 3, 4, 5},
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		ft_bzero((void *) tests[i].s, tests[i].n);
		if (memcmp(tests[i].s, tests[i].expected, 5) != 0)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW"{%d, %d, %d, %d, %d}"DEFAULT, tests[i].expected[0], tests[i].expected[1], tests[i].expected[2], tests[i].expected[3], tests[i].expected[4]);
			printf(CYAN" got "YELLOW"{%d, %d, %d, %d, %d}\n"DEFAULT, tests[i].s[0], tests[i].s[1], tests[i].s[2], tests[i].s[3], tests[i].s[4]);
			return (-1);
		}
		i++;
	}
	return (0);	
}
