#include<stdio.h>
#include<conio.h>
#include<stdlib.h>	
	
struct dugum{
	
int data;	
struct dugum *previous;
struct dugum *next;	

};	
	 
struct dugum *ciftyonluinsert(struct dugum *x,int veri)
{
		struct dugum *yeni=(struct dugum*)	malloc( sizeof(struct dugum) );
		
		yeni->data=veri;
		yeni->next=NULL;
		yeni->previous=NULL;
		
	if(x==NULL)
	{
	x=yeni;
	}
	
else
{
	struct dugum *gecici=x;
	struct dugum *onceki=NULL;
		
	while(gecici->next)
	{
		onceki=gecici; 
		gecici=gecici->next;
		gecici->previous=onceki;
	}
		
	  gecici->next=yeni;
	  yeni->previous=gecici;
}
	
	return x;
}
	
		
int main(){
	
	struct dugum *x=NULL;
	int veri;
	char karakter;
		
	printf("Devam etmek istediginiz surece sayi girin\n");
	
	do{
	
	printf("Veri girin\n");	
	scanf("%d",&veri);
	
	printf("Devam edecekseniz E tusuna basin\n");
	karakter=getch();
	
	x=ciftyonluinsert(x,veri);
	
	}while(karakter=='E');

	struct dugum*temp=x;
	
	while(temp)
	{
	printf("Adres=%x--Oncekinin adresi=%x--Sonrakinin adresi=%x--Degeri=%d\n",temp,temp->previous,temp->next,temp->data);	
	temp=temp->next;
	}
	
	
getch();
return 0;	
}
