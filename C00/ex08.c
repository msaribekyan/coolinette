#include <unistd.h>

void ft_print_combn(int n);

int	main()
{
	int	i;
	char	c;

	i = 1;
	c = '\n';
	while (i < 10)
	{
		ft_print_combn(i);
		write(1, &c, 1);
		i++;
	}
	return 0;
}
