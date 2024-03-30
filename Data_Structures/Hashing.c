#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

 typedef struct {
 	
 int musteri_no;
 char ad[SIZE*2],soyad[SIZE*2];

 }Musteri;

  Musteri *veri_liste[SIZE];
  int hash_tablo[10];


	void initialize_table(int atama,int flag){
	
	int sayac = 0;

	if(!flag)	
	{	
		while(sayac++<SIZE)		hash_tablo[sayac] = atama;	
	}
	
	else(flag==1)
	{
		veri_liste[atama++]->ad[0] = 0;
		veri_liste[atama++]->soyad[0] = 0;
		veri_liste[atama++]->musteri_no = -1;
	 }
	
}
	   int h1(int numara){
			
	   return ( ( 3 * numara ) + 2 ); 	
	   }
	   
	   		int h2(int numara){
	   		
	   		return ( 7 * ( numara + 2 ) );	
		   }
	   
		void ekle(int numara,char *isim,char *soyisim,int x){
			
			int deger=h1(numara)%10;
			
			initialize_table(x,1);
			
			hash_tablo[x]=deger;				
			veri_liste[x]->musteri_no=deger;		printf("%d-",veri_liste[x]->musteri_no);
			
			strcpy(veri_liste[x]->ad, isim); 		printf("%s-",veri_liste[x]->ad);
			strcpy(veri_liste[x]->soyad, soyisim);	printf("%s\n",veri_liste[x]->soyad);					
		} 

 int main(){

 int j=0,numara,atama=0;
  char *isim,*soyisim;
 
   FILE *fp;
   fp=fopen("veri.txt","r+");
 
  	initialize_table(atama,0);
 
 	 while(j++<7){
 		
 		isim=(char *)    malloc( sizeof(char) *10 );
 		soyisim=(char *) malloc( sizeof(char) *10 );
 		
 		fscanf(fp,"%d %s %s",&numara,isim,soyisim);	
	
 			veri_liste[j]=(Musteri*) malloc(sizeof(Musteri));
 		
 		ekle(numara,isim,soyisim,j);
	   }	

  getch();
  return 0;	
}
