#include<stdio.h>
#include<conio.h>

void reverse(int deger)
{
	
	if(!deger) {printf(" %d",deger); return;} 
	
	    else if (deger < 0)
		{	
			printf(" %d", deger);
			reverse(deger + 1);
		}
		
		else
		{
			printf(" %d", deger);
			reverse(deger - 1);
		}

}


int main()
{		
 int sayi;
		
  printf("tersten yazdirmak istediginiz sayiyi giriniz:");
  scanf("%d",&sayi);

	reverse(sayi);	
	
 getch();
  return 0;	
 }
