#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct dugum{
    
int data;    
struct dugum *previous;
struct dugum *next;    

}node;

int flag = 0;

node *ciftyonluinsert(node *x,int veri)
{
        node *yeni=(node*)    malloc( sizeof(node) );
        
        yeni->data=veri;
        yeni->next=NULL;
        yeni->previous=NULL;
        
    if(x==NULL)
    {
	    x = (node*)    malloc( sizeof(node) );
	    x->data=veri;
	    x->next=NULL;
	    x->previous=NULL;
    }
    
    else
    {
   node *gecici=x;
   node *onceki=NULL;
        
    
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
    
    
node *ciftyonludelete(node *x,int aranan)
{
	
	node *y;
	
    if(x->data==aranan)
    {
    	
    	flag=1;
		free(x=x->next);
    }
    
    else
    {
	  	node *gecici=x->next;
	    
	    while ( gecici->data!=aranan && gecici->next )
	    {
	    	gecici=gecici->next;
		}

		
		flag=1;
		
			gecici->previous->next=gecici->next;
	    
	    	if(gecici->next)    gecici->next->previous=gecici->previous;
	    	
	    		if(gecici->next==NULL && gecici->data!=aranan)	flag=0;
    }
    
    return x;
}

int main()
{
    node*x=NULL;
    int aranan;
    int veri;
    int karakter;
    
        printf("Devam etmek istediginiz surece sayi girin\n");
    
    do
	{
    printf("Veri girin\n");    
    scanf("%d",&veri);
    
        x=ciftyonluinsert(x,veri);
        
    printf("Devam edecekseniz E tusuna basin\n");
    karakter=getch();
    
    }while(karakter=='E');

    
    printf("\nAranani girin ");
    scanf("%d",&aranan);
    
    x=ciftyonludelete(x,aranan);
    
    
    if (flag)
    {
    	struct dugum*temp=x;
	    
	    while(temp)    
	    {
		    printf("Adres=%x--Oncekinin adresi=%x--Sonrakinin adresi=%x--Degeri=%d\n",temp,temp->previous,temp->next,temp->data);    
		    temp=temp->next;
	    }
	}
    else
    {
    	printf("Aradaiginiz veri listede yok");
	}

	getch();
	return 0;
}
