#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Dugum
{
	int sayi;
	struct Dugum *next;
};

int main()
{
	int i, num;
	char k;
	
	struct Dugum *liste = NULL, *temp = NULL;
	
	do
	{
		if (liste == NULL)
		{
			liste = (struct Dugum *) malloc(sizeof(struct Dugum));
			
			scanf("%d", &(liste->sayi));
			liste->next = NULL;
			
			printf("Adress: %x, Value: %d\n", liste, liste->sayi);
	    }
	   
		else
		{
			temp = (struct Dugum *) malloc(sizeof(struct Dugum));
			
			printf("\nSayi girin: ");
			scanf("%d", &(temp->sayi));
			
			printf("Adress: %x, Value: %d\n", temp, temp->sayi);
			
			temp->next = liste;
			liste = temp;
		}
		printf("\nDevam etmek istiyor musunuz? (E/H) : ");
		k = getch();
	}
	while (k == 'E');
	
	printf("\n");
	
	if (temp == NULL)
	{
		printf("\nBagli Liste Olusturulmamis!");
	}
	
	else
	{
		while (liste != NULL)
		{
			printf("Adress: %x, Value: %d, NextAdress: %x\n", liste, liste->sayi, liste->next);
			liste = liste->next;
		}
	}
	
	getch();
	return 0;
}
