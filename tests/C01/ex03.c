#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod);

int main(){
	int a=1010;
	int b=7;
	int div;
	int mod;
	ft_div_mod(a, b, &div, &mod);
	printf("%d %d", div, mod);
	return 0;
}
