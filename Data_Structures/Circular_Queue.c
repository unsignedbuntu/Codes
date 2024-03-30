#include <stdio.h>
#include <conio.h>

int size = 3;

typedef struct CircularTail
{
	int first;
	int last;
	int count;
	int d[100];
} CTail;

CTail ck1;
ck1.first = ck1.last = -1;
	ck1.count = 0;
	

int IsFullOrEmpty(int mode) // mode 1 = empty
{
	return (mode ? (ck1.count == 0) : (ck1.count == size));
}

void Add(int n)
{
	if (IsFullOrEmpty(0))
	{
		printf("FULL!\n");
		
		return;
	}
	
	ck1.d[ck1.last = (ck1.last + 1) % size] = n;
	ck1.count++;
}

int Remove()
{
	if (IsFullOrEmpty(1))
	{
		printf("EMPTY!\n");
		
		return 0;
	}
	
	int ret = ck1.d[ck1.first = (ck1.first + 1) % size];
	
	ck1.count--;
	
	return (ret);
}

void ListAll()
{
	int i;
	
	for (i = 0; ++i <= ck1.count; printf("%d ", ck1.d[(ck1.first + i) % size]));
}

int main()
{
	ck1.first = ck1.last = -1;
	ck1.count = 0;
	
	Add(15);
		Add(45);
		Add(35);
		Remove();
	
		Add(70);
				
	ListAll();
	
	return (!getch());
}
