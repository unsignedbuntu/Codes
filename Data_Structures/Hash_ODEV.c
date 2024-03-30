#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct {
	int musteri_no;
	char ad[20], soyad[20];
} Musteri;

Musteri *veri_liste[SIZE];
int hash_tablo[SIZE];


void initialize_table(int atama) {
	
	int sayac = 0;
	
	while(sayac < SIZE) {
		hash_tablo[sayac] = atama;	
			
		veri_liste[sayac]->ad[0] = '\0';
		veri_liste[sayac]->soyad[0] = '\0';
		veri_liste[sayac]->musteri_no = atama;

		sayac++;
	}	
}

int h1(int numara) {
	return ((3 * numara) + 2);
}

int h2(int numara) {
	return (7 * (numara + 2));
}
	   
void ekle(int numara, const char *isim, const char *soyisim) {
	
	int deger1 = h1(numara)%10;
	int deger2 = h2(numara)%10;
	int indis=deger1;
	
	if (hash_tablo[indis] != -1) {
		
		int i;
		for (i = 1; i < 10; i++)
		{
			if (hash_tablo[indis] == -1)
				break;
			
			indis = (deger1 + (i * deger2)) % 10;
		}
	}
							
	hash_tablo[indis] = numara;
	veri_liste[indis]->musteri_no=numara;
	strcpy(veri_liste[indis]->ad, isim);
	strcpy(veri_liste[indis]->soyad, soyisim);
}

void listele() {
	int i;
	
	for (i = 0; i < SIZE; i++) {
	 	if (hash_tablo[i] == -1)
			continue;
		
		printf("[%d] - %d %s %s\n", i, veri_liste[i]->musteri_no, veri_liste[i]->ad, veri_liste[i]->soyad);
	}
}

int *bul(int sayi) {
	
	int indis,sayac = 1;
	
	indis=h1(sayi)%10;
	
	int *d = (int*) malloc(sizeof(int) * 3);
	
	d[0] = 0;
	d[1] = -1;
	d[2] = -1;
	
	if(hash_tablo[indis]==sayi)
	{
		d[0] = 1;
		d[1] = indis;
		d[2] = sayac;
		
		return d;
	}
	else
	{
		for(sayac=1;sayac<SIZE+1;sayac++) {
			
			indis = ( h1(sayi) + sayac * h2(sayi)) % 10;
			
			if(hash_tablo[indis]==sayi)
			{
				d[0] = 1;
				d[1] = indis;
				d[2] = sayac+1;
				
				break;
			}
		}
		
		return d;
	}
}

void ortalamagoster()
{
	int i, adimtoplam = 0, sayac = 0;
	
	for (i = 0; i < SIZE; i++) {
	 	if (hash_tablo[i] == -1)
			continue;
		
		int *gecici = bul(hash_tablo[i]);
		
		adimtoplam += gecici[2];
		sayac++;
	}
	
	printf("\n\nortalama adim sayisi = %.2f", (float)adimtoplam / sayac);
}

int main() {
	
    int j = -1, numara,sayi;
    char *isim, *soyisim;
 
    FILE *fp;
    fp = fopen("veri.txt","rb");
    
	if (!fp) {
		perror("Dosya acilamadi\n");
		return 1;
	}

	while(j++ < 9) veri_liste[j]=(Musteri*) malloc(sizeof(Musteri));
 	
 	initialize_table(-1);
 
 	j = 0;
 
 	while(j++ < 7) {
 		
		isim = (char*) malloc(sizeof(char)*10);
		soyisim = (char*) malloc(sizeof(char)*10);
		
 		fscanf(fp,"%d %s %s", &numara, isim, soyisim);	

 		ekle(numara, isim, soyisim);
	}
	
	
	fclose(fp);
	
	listele();
	
	printf("\n\nBulunmasini istediginiz sayiyi girin:");
	scanf("%d",&sayi);
	
	int *bul_sonuc = bul(sayi) ;
	
	if(bul_sonuc[0]==0) 	printf("\nVeri bulunamadi!\n");
	
	else {
		printf("Veri %d adimda bulundu\n",bul_sonuc[2]);
		printf("%d %s %s", hash_tablo[bul_sonuc[1]], veri_liste[bul_sonuc[1]]->ad, veri_liste[bul_sonuc[1]]->soyad);
	}
	
	ortalamagoster();
	
	getch();
	return 0;	
}
