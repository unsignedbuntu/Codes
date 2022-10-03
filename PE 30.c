//PE=Project Euler
#include<stdio.h>
#include<conio.h>
#define POWEROF5 digit*digit*digit*digit*digit
//1634 = 1^4 + 6^4 + 3^4 + 4^4
//8208 = 8^4 + 2^4 + 0^4 + 8^4
//9474 = 9^4 + 4^4 + 7^4 + 4^4
//The sum of these numbers is 1634 + 8208 + 9474 = 19316.
//Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
int main(){
	
int number,temp,sum,digit,sumsum=0;
	
	printf("Sarti saglayan sayilar\n\n");
	
for(number=2;number<1000000;number++)
{
	temp=number;
	sum=0;
	
	while(temp>0)	
	{	
	digit=temp%10;
	sum+=POWEROF5;
	temp/=10;	
	}
	
	sum==number ?	sumsum+=sum,	printf("%d-",sum) : printf("");
}

printf("\n\nSarti saglayan sayilarin sayilar toplami=%d",sumsum);

getch();
return 0;	
}
