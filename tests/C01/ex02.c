#include <stdio.h>

void	ft_swap(int *a, int *b);

int main(){
	int a = 2147483647;
	int b = -2147483648;
	
	ft_swap(&a, &b);
	
	printf("%d %d", a, b);
	return 0;
}
