#include <stdio.h>

int main()
{
	int n;
	struct point
	{
		float abississa;
		float ordenada;
	};
	
	printf("Quantos pontos serão dados? ");
	scanf("%i", &n);
	struct point points[n];
	
	for (int i = 0; i < n; i++)
	{
		printf("\nPonto %i:\n", i+1);
		printf("abississa: ");
		scanf("%f", &points[i].abississa);
		printf("ordenada: ");
		scanf("%f", &points[i].ordenada);
	}
	
	for(int i = 0; i < n; i++)
	{
	    printf("\nx: %9.5f, y: %9.5f", points[i].abississa, points[i].ordenada);
	}
	printf("\n\n\n\n");
	for (int i = 0; i < n; i++)
	{
	    printf("%f * ((", points[i].ordenada);
	    for (int j = 0; j < n; j++)
	    {
	        if(!(j==i)){printf("(x - %f)", points[j].abississa);}
	        if((j < n-1) && !(j==i) && !(j+1==i)){printf("*");}
	    }
	    printf(")/(");
	    for(int j = 0; j < n; j++)
	    {
	        if(!(j==i)){printf("(%f - %f)", points[i].abississa, points[j].abississa);}
	        if((j < n-1) && !(j==i) && !(j+1==i)){printf("*");}
	    }
	    printf("))");
	    if(i < n-1){printf("+");}
	}
	
	return 0;
}