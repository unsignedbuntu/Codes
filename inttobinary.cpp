#include<stdio.h>
#include<conio.h>

int Oiss_Gecis(int x)
{
    return (x ? ( Oiss_Gecis(x / 2) * 10 + x % 2 ) : 0);
}

int main()
{	

int x;
scanf("%d",&x);

printf("%d",Oiss_Gecis(x) );

getch();
return 0;

}
