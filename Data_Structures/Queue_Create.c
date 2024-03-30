#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Dugum
{
	int vize;
	int final;
	struct Dugum *next;
};

int main()
{
	int i, num,sayac;
	char k;

	struct Dugum *liste = NULL, *temp = NULL;
		
	printf("Kac ogrenci giriceksiniz? ");
	scanf("%d",&sayac);
	
	printf("\nSirasiyla her seferinde 1.vize 2.final olucak sekilde notlari giriniz\n\n");
	
	while(sayac-->0)
	{
		if (liste == NULL)
		{
			liste = (struct Dugum *) malloc(sizeof(struct Dugum));
			
			printf("%d.ogrenci--",sayac+1);
			
			scanf("%d", &liste->vize);
			scanf("%d", &liste->final);
			
			liste->next = NULL;
			
			temp = liste;
			
			printf("Address: %x, Vize: %d, Final: %d\n", liste, liste->vize,liste->final);
		}
		
		else
		{
			temp->next = (struct Dugum *) malloc(sizeof(struct Dugum));
			
			printf("%d.ogrenci--",sayac+1);
			
			scanf("%d", &(temp->next->vize));
			scanf("%d", &(temp->next->final));
			
			printf("Address: %x, Vize: %d, Final: %d\n", temp->next, temp->vize,temp->final);
			
			temp = temp->next;
			
			temp->next = NULL;
		}
	}
	
	printf("\n");
	
	temp = liste;
	
	if (temp == NULL)
	{
		printf("\nBagli Liste Olusturulmamis!");
	}
	
	else
	{
		while (temp != NULL)
		{
			printf("Address: %x, Vize: %d, Final: %d, NextAdress: %x\n", temp,temp->vize,temp->final,temp->next);
			temp = temp->next;
		}
	}
	
	getch();
	return 0;
}
