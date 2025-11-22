#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main()
{
	int s1[5] = {5, 2, 4, 3, 1};
	ft_sort_int_tab((int *)&s1, 5);
	for(int i = 0;i < 5;i++){
		printf("%d ", s1[i]);
	}

	int s2[6] = {5, 6, 2, 4, 1, 3};
	ft_sort_int_tab((int *)&s2, 6);
	for(int i = 0;i < 6;i++){
		printf("%d ", s2[i]);
	}
	return 0;
}
