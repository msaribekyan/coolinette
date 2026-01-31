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
	unsigned char	d[5];
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
			.desc = "ft_memcpy(\"{1, 2, 3, 4, 5}, {6, 7, 8, 9 ,0}, 5\")",
			.d = {1, 2, 3, 4, 5},
			.s = {6, 7, 8, 9, 0},
			.n = 5,
			.expected = {6, 7, 8, 9, 0},
		},
		{
			.desc = "ft_memcpy(\"{1, 2, 3, 4, 5}, {6, 7, 8, 9 ,0}, 3\")",
			.d = {1, 2, 3, 4, 5},
			.s = {6, 7, 8, 9, 0},
			.n = 3,
			.expected = {6, 7, 8, 4, 5},
		},
		{
			.desc = "ft_memcpy(\"{1, 2, 3, 4, 5}, {6, 7, 8, 9 ,0}, 0\")",
			.d = {1, 2, 3, 4, 5},
			.s = {6, 7, 8, 9, 0},
			.n = 0,
			.expected = {1, 2, 3, 4, 5},
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		unsigned char *output = (unsigned char *) ft_memcpy((void *) tests[i].d,(void *) tests[i].s, tests[i].n);
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
