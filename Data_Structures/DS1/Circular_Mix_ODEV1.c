#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Dugum{
	
	struct Dugum *sonraki;
	char *yemek_adi;
	int yemek_gramaji;
	float yemek_fiyati;	
	
}DugumListe;

DugumListe *son=NULL, *ilk=NULL;

void Ekleme(char *ad,int gramaj,float fiyat)
{
	DugumListe *Olustur=(DugumListe*) malloc(sizeof(DugumListe) );	
		
	Olustur->yemek_adi=ad;
	Olustur->yemek_gramaji=gramaj;
	Olustur->yemek_fiyati=fiyat;
	
	int bayrak=0;
	
	if(ilk==NULL)  { son=ilk=Olustur; ilk->sonraki=ilk; }
	
	if(Olustur->yemek_fiyati <= ilk->yemek_fiyati)
	{
		Olustur->sonraki=ilk;
		ilk=Olustur;
		son->sonraki=Olustur;
		bayrak=1;
	}
	
	if(son->yemek_fiyati <= Olustur->yemek_fiyati)
	{
		son->sonraki=Olustur; 
		son = Olustur;
		son->sonraki=ilk;
		bayrak=1;
	}
	
	if(!bayrak)
	{
		DugumListe *yedek=ilk; //her seferÄ±nde bastan sonra kontrol Ä±cÄ±n yedegÄ± tutan degÄ±sken
		
		while(Olustur->yemek_fiyati >= yedek->sonraki->yemek_fiyati)
		{
			Olustur=Olustur->sonraki;
		}
		
		Olustur->sonraki=yedek->sonraki; 
		yedek->sonraki = Olustur;
	}
}

void Silme(char aranan[])
{	
DugumListe *Silmegecici=ilk;
int flag=0;

if(strcmp(Silmegecici->yemek_adi, aranan) == 0) 
{	
flag=1;
free(ilk=ilk->sonraki);//ilk elemaný bý sonrakýne al ve sil
son->sonraki=ilk;
}

while(strcmp(Silmegecici->sonraki->yemek_adi,ilk->yemek_adi ) !=0){
	
if(strcmp(Silmegecici->sonraki->yemek_adi,aranan) ==0)	
{	
Silmegecici->sonraki=Silmegecici->sonraki->sonraki; //arananý bulduysak onceký elemaný arananýn sonrasýna baglayalým 
free(Silmegecici->sonraki);	
flag=1;
 Silmegecici=Silmegecici->sonraki;
break;
}

 Silmegecici=Silmegecici->sonraki;
}


if(!flag)	printf("Silmek istediginiz isim listedek yok!");

}

void Listele()
{
	DugumListe *Listelegecici=ilk;
	
	do
	{
		printf("%s %d %f\n",Listelegecici->yemek_adi,Listelegecici->yemek_gramaji,Listelegecici->yemek_fiyati);
		Listelegecici=Listelegecici->sonraki;
	}
	while(Listelegecici!=ilk); //son elemandan bir sonraki eleman ilk elemana baglanmadÄ±gÄ± surece
}

void YemekSecim(DugumListe *gecici){
}

int main()
{
	FILE *fp=fopen("Yemek.txt","r");	
	DugumListe *gecici=NULL;
	int sayac=8,secim;
	char yemek_adi[4][200],aranan[50];
	int yemek_gramaji;
	float yemek_fiyati;	
	
	printf("Ilk once dosyadan okumak icin ekleme islemini 4 defa kullanin!!!\n\n");
	
	while(sayac-- > 0)
	{
		printf("\n%sSilme icin:2\nListeleme icin:3\nYemekSecimi icin:4'e\nCikis icin 5'e basin:", sayac > 3 ? "\nEkleme icin:1\n" : "");//dosyayÄ± okuduktan sonra tekrar ekleme yapmasÄ±na gerek yok
		
		scanf("%d",&secim);
		
		if(secim==1)
		{
			fscanf(fp,"%s %d %f",yemek_adi[7 - sayac],&yemek_gramaji,&yemek_fiyati); 
			Ekleme(yemek_adi[7 - sayac],yemek_gramaji,yemek_fiyati);
		}
		
		if(secim==2) {printf("\nSilmek istediginiz yemegi girin:"); scanf("%s",aranan);
		Silme(aranan);
		}
		
		if(secim==3) Listele();
		if(secim==4) YemekSecim(gecici);
		if(secim==5)	{printf("\nSonlandirdiniz");
		exit(0);
		}
	}
	
	fclose(fp);
	getch();
	return 0;
}
