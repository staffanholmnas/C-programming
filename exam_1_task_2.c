#include <stdio.h>

int main()
{
	
	int n;
	int i;
	
	do
	{
		printf("give a whole number\n");
		scanf("%d", &n);
	}
	while(n < 6 || n > 60);
	
	for (i = 0; i < n; i++)
		printf("Staffan\n");  // or "your name" ;)
		
	return 0;
}
