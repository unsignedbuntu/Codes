#include<stdio.h>
#include<conio.h>

int main(){
	
	unsigned int tarih=0;
	int gun,ay,yil;
	
	printf("Gun ay yil girin:");
	scanf("%d%d%d",&gun,&ay,&yil);
	
	tarih|=yil;
	tarih|=ay<<7;
	tarih|=gun<<11;
	
	printf("%u/%u/%u",tarih>>11,tarih<<21>>28,tarih<<25>>25);
	
	
	
getch();
return 0;	
}
