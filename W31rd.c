//W31rd=Weird
//one of my first code thats why has a lot of mistakes still dont know how it works just random code 
#include <stdio.h>

int main()
{
int a,b,x=0,y=0;
char choice;

printf(" x'i'girin");
scanf("%d",&x);

printf(" y'yi'girin");
scanf("%d",&y);

	
    while(scanf("%c",&choice))
    {
for(a=0;a<x;a++)	
{
	for(b=0;a+b<y;b++)	
	{
	printf(" ");	
	}
	
		for(b=0;a+b<10;b++)
		{
		printf("\xdb");
		b++;
		}
		
	printf("\n");
}
        if(choice=='w')
        {
            x--;
            printf("*");

        }
        else if(choice=='s')
        {
            x++;
        printf("*");

        }
        else if(choice=='a')
        {
            y--;
            printf("*");	
		}
        else if(choice=='d')
        {
            y++;
            printf("*");
    	}
     }
            return 0;
        }
