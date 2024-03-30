 #include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	srand(time(0));
	unsigned int dizi[100],gecici;
	int sayac=0,a=0;
	
	FILE *dosyaw,*dosyar;
	
	dosyaw=fopen("sayi.txt","w+");
	
	if(!dosyaw)
	{
	printf("dosya acma hatasi!");
	return 0;
	}
	
	for(;a<100;a++)
	{
	fprintf(dosyaw,"%u\n",rand()%99+1);
	}
	
	fclose(dosyaw);
	
		dosyar=fopen("sayi.txt","r+");
	
	if(!dosyar)
	{
	printf("dosya acma hatasi!");
	return 0;	
	}
	
	int *x= (int *) malloc( sizeof(int) );
	
	int temp=sizeof(int);
	
	for(a=0;a<100;a++)
	{
	fscanf(dosyar,"%u",&gecici);
	
		if( !(gecici & 1<<4) )
		{
		 x= (int *) realloc(x, temp+=4 );	
		 dizi[a]=gecici;	
	     printf("%u|",dizi[a]);
		}
	}
free(x);
getch();
return 0;
}
