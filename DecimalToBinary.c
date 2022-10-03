#include<stdio.h>
#include<conio.h>

void printAsBinary(unsigned int x)
{
	unsigned int i = 1U << 31;

    for (unsigned int i = 1U << 31; i; i >>= 1)
    {
        printf("%d", (x&i) == i); 
    }
}

int main()
{
unsigned int sayi;

scanf("%u",&sayi);	
	
printAsBinary(sayi);	
	
getch();	
return 0;	
}
