
//2'nin Kuvveti mi?

#include<stdio.h>
#include<conio.h>


int onlytwodivcheck(unsigned int sayi)
{
	
int sayac=0;
 unsigned int sj=31;
	
for(;sayi>0;sayi>>=1)
{
	if(  sayi & 1 )		sayac++;		
}

if(sayac==1)	return 1;

return 0;	
		
}


int main(){
	
unsigned int deger;	
	
printf("2'nin kuvveti olup olmadigini kontrol etmek istediginiz sayiyi girin:");
scanf("%u",&deger);	
	
onlytwodivcheck(deger)==1  ? printf("girdiginiz sayi 2'nin kuvvetidir ") : printf("girdiginiz sayi 2'nin kuvveti degildir");

getch();
return 0;	
}
