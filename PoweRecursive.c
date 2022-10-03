#include<stdio.h>
#include<conio.h>

//usalma recursive


float usalma(int deger,int taban)
{
	
if(!taban) return 1; //if power is equal 0

if(!deger)	return 0;	

// (5,2)*5||(5,2)|||||(5,1)*5	
if(taban==1) return deger; 


if(taban>0) return ( usalma(deger,taban-1)*deger ); //for positive power	
if(taban<0) return ( 1 / (usalma(deger,-(taban+1) )*deger) );	// for negative power
if(deger<0 && taban%2==1) return( -usalma(deger,taban-1)*deger );  //for negative number
}

int main(){
	
	int sayi;
	int taban;
	
	printf("Us alincak sayiyi giriniz:");
	scanf("%d",&sayi);
	
	printf("Tabani giriniz:");
	scanf("%d",&taban);
	
	printf( "%d^%d=%f",sayi,taban,usalma(sayi,taban) );
	
getch();
return 0;	
}
