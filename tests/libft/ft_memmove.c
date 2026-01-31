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
	unsigned char	start[10];
	unsigned char	*d;
	unsigned char	*s;
	size_t		n;
	unsigned char	expected[10];
}	t_test;

void print_arr(unsigned char *arr, size_t len)
{
	size_t i;

	i = 0;
	printf("{");
	while (i < len - 1)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf("%d}", arr[i]);
}

int main()
{
	int	i;
	int	count;

	t_test tests[] = {
		{
			.desc = "ft_memmove(\"{1, 2, 3, 4, 5}, {4, 5, 6, 7, 8}, 5\")",
			.start = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
			.d = tests[0].start,
			.s = tests[0].start + 3,
			.n = 5,
			.expected = {4, 5, 6, 7, 8, 6, 7, 8, 9, 0},
		},
		{
			.desc = "ft_memmove(\"{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, 5\")",
			.start = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
			.d = tests[1].start,
			.s = tests[1].start,
			.n = 5,
			.expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
		},
		{
			.desc = "ft_memmove(\"{4, 5, 6, 7, 8}, {1, 2, 3, 4, 5}, 5\")",
			.start = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
			.d = tests[2].start + 3,
			.s = tests[2].start,
			.n = 5,
			.expected = {1, 2, 3, 1, 2, 3, 4, 5, 9, 0},
		},
	};
	count = sizeof(tests) / sizeof(t_test);
	i = 0;
	while (i < count)
	{
		unsigned char *output = (unsigned char *) ft_memmove((void *) tests[i].d,(void *) tests[i].s, tests[i].n);
		if (output != tests[i].d)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(YELLOW"Pointers do not match"DEFAULT);
			return (-1);
		}
		if (memcmp(tests[i].start, tests[i].expected, 10) != 0)
		{
			printf(RED "TEST FAILED" DEFAULT " %s\n", tests[i].desc);
			printf(CYAN "Expected "YELLOW);
			print_arr(tests[i].expected, 10);
			printf(DEFAULT);
			printf(CYAN" got "YELLOW);
			print_arr(tests[i].start, 10);
			printf("\n"DEFAULT);
			return (-1);
		}
		i++;
	}
	return (0);	
}
