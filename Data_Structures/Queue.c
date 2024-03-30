#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int KBoyut = 100;

typedef struct Tail
{
	int son;
	int eleman[100];
} Kuyruk;

Kuyruk k1;

int IsFullOrEmpty(int mode) // mode 1 = empty
{
	return (mode ? k1.son == -1 : k1.son + 1 == KBoyut);
}

void Add(int n)
{
	if (IsFullOrEmpty(0))
	{
		return;
	}
	
	k1.eleman[++k1.son] = n;
}

void Remove()
{
	if (IsFullOrEmpty(1))
	{
		return ;
	}
	
	int i, removed = k1.eleman[0];
	
	for (i = 0; i < KBoyut - 1; i++)
	{
		k1.eleman[i] = k1.eleman[i + 1];
	}
	
	printf("%d-",k1.son);
	k1.eleman[k1.son--] = 0;
}

int main()
{
	int i;
	k1.son = -1;

	Add(30);
	Add(40);
	Add(35);
	Add(50);
	Add(310);
	Add(390);
	Remove();
	
	for (i = 0; i <= k1.son; i++)
	{
		printf("%d ", k1.eleman[i]);
	}
	
	return (!getch());
}

