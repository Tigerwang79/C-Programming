#include <stdlib.h>
#include <stdio.h>

void f_correct()
{
	static int n = 3;
	n++;
	printf("%d\n", n);
}

void f_faux()
{
	static int n;
	n = 3;
	n++;
	printf("%d\n", n);
}