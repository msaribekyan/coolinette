#include <unistd.h>

void ft_putnbr(int nbr);

int	main()
{
	char	c;

	c = '\n';
	ft_putnbr(1010);	
	write(1, &c, 1);
	ft_putnbr(0);
	write(1, &c, 1);
	ft_putnbr(-1010);
	return 0;
}
