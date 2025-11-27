#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int	main()
{
	int s1[5] = {1, 2, 3, 4, 5};
	ft_rev_int_tab((int *)&s1, 5);
	for(int i = 0;i < 5;i++){
		printf("%d ", s1[i]);
	}

	int s2[6] = {1, 2, 3, 4, 5, 6};
	ft_rev_int_tab((int *)&s2, 6);
	for(int i = 0;i < 6;i++){
		printf("%d ", s2[i]);
	}
	return 0;
}
