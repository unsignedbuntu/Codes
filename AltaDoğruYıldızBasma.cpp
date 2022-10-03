//42 ASCII KARSILIGI=*

#include <stdio.h>
#include <conio.h>
#include<time.h>
#include<stdlib.h>

#define KONYA 42

void sekil_basma(int d[])
{
	int i, j;
	
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			d[j]-- > 0 ? printf("%c",KONYA) : printf(" ");
		}
		
		printf("\n");
	}
}

int main()
{
	
srand(time(NULL));

	int dizi[10],a=0;
	
	for(a;a<10;a++) 		dizi[a]=rand()%10;	
	
	sekil_basma(dizi);
	
	getch();
	return 0;
}
