#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define YERAYIR ((struct Node*) malloc(sizeof(struct Node)))

struct Node
{
	int x;
	struct Node *next;
};

struct Node *ENQUEUE(struct Node *liste, int sayi)
{
		struct Node *yeni = YERAYIR;
		
		yeni->x    = sayi;
		yeni->next = NULL;
	
	if (liste == NULL)		liste = yeni;
	
	else
	{
		if (liste->next == NULL)		liste->next = yeni;
		
		else
		{
			struct Node *temp    = liste;
			struct Node *onceki  = liste;
			struct Node *nextemp = NULL;
			
			while (temp != NULL && ((temp->x) <= sayi)) // 1 2 3 *
			{
				onceki = temp;
				temp = temp->next;
			}
			
			if (temp == NULL)
			{
				struct Node *yenii = YERAYIR;
				
				onceki->next = yenii;
				
				yenii->x = sayi;
				yenii->next = NULL;
			}
			else
			{
				struct Node *yenix = YERAYIR;
				
				onceki->next = yenix;
				
				yenix->x = sayi;
				yenix->next = temp;
			}
		}
	}
	
	return (liste);
}

int main()
{
	struct Node *list = NULL;
	
	srand(time(0));
	
	int i, d[10] = { rand()%50+5,rand()%50+5,rand()%50+5,rand()%50+5,rand()%50+5,rand()%50+5,rand()%50+5,rand()%50+5,rand()%50+5,rand()%50+5 };
	
	for (i = 0; i < 10; i++)
	{
		list = ENQUEUE(list, d[i]);
	}
	
	if (list)
	{
		struct Node *temp = list;
		
		while (temp)
		{
			printf("%x,     %d,     %x\n", temp, temp->x, temp->next);
			temp = temp->next;
		}
	}
	
	getch();
	return 0;
}
