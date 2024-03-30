#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define   BUYUKHARFMI(x)     (x >= 'A' && x <= 'Z')
#define   KUCUKHARFMI(x)     (x >= 'a' && x <= 'z')
#define        SAYIMI(x)     (x >= '0' && x <= '9')
#define    PARANTEZAC(x)     (x == '(')
#define PARANTEZKAPAT(x)     (x == ')')
			
int kelime_sayisi = 0;
int tam_kelime    = 0;
int satir         = 0;

char **kelimeler  = NULL;

typedef struct stack
{
	char **kelime;
	int index;
} Yigin;

Yigin y_1, y_2;

int basamaksayisi(int sayi)
{
	int sayac;
	
	for (sayac = (sayi == 0 ? 1 : 0); sayi; sayi /= 10, sayac++);
	
	return sayac;
}

int boslukindisi(char *yazi)
{
	int i;
	
	for (i = 0; yazi[i] != ' '; i++);
	
	return i;
}


void sayac(char *input)
{
	int i, say = 0;
	
	for (i = 0; input[i]; i++)
	{
		if (BUYUKHARFMI(input[i]) || SAYIMI(input[i]) || PARANTEZAC(input[i]) || PARANTEZKAPAT(input[i]))
		{
			while (SAYIMI(input[i]) && SAYIMI(input[i + 1]))
			
				i++;
			
			
			say++;
		}
	}
	
	kelime_sayisi = say;
}

int sayiyadonustur(char *yazi)
{
	int i, on = 1, toplam = 0;
	
	for (i = strlen(yazi) - 1; i >= 0; i--)
	{
		toplam += (yazi[i] - '0') * on;
		on *= 10;
	}
	
	return toplam;
}

char *yaziyadonustur(int sayi)
{
	char *yazi = (char*) malloc(sizeof(char) * (basamaksayisi(sayi) + 1));
	
	int i, gecici = sayi;
	
	for (i = basamaksayisi(sayi) - 1; i >= 0; i--)
	{
		yazi[i] = sayi % 10 + '0';
		sayi /= 10;
	}
	
	yazi[basamaksayisi(gecici)] = '\0';
	
	return yazi;
}

void doldur(char *input)
{
	int i, t, sutun, sayac;
	
	for (i = 0; input[i]; i++) // Kr4(OnNe(SOne3)26)2
	{
		kelimeler[satir][sutun = 0] = t = input[i];
		
		while ((BUYUKHARFMI(t) || SAYIMI(t)) ? (SAYIMI(t) ? SAYIMI(input[i + 1]) : KUCUKHARFMI(input[i + 1])) : 0)
		{
			kelimeler[satir][++sutun] = input[++i];
		}
		
		kelimeler[satir++][++sutun] = '\0';
		if (BUYUKHARFMI(t)) tam_kelime++;
	}
	
	for (i = 0; i < kelime_sayisi; i++)
	{
		if (BUYUKHARFMI(kelimeler[i][0]))
		{
			strcat(kelimeler[i], ": 1");
		}
	}
}

int dolumu(int no)
{
	return (no == 1 ? y_1.index : y_2.index) == kelime_sayisi;
}

int bosmu(int no)
{
	return (no == 1 ? y_1.index : y_2.index) == 0;
}

void Ekle(char *yazi, int no)
{
	no == 1 ? strcpy(y_1.kelime[y_1.index++], yazi) : strcpy(y_2.kelime[y_2.index++], yazi);
}

char *Cikar(int no)
{
	char *gecici = (char*) malloc(sizeof(char) * 100);
	
	strcpy(gecici, no == 1 ? y_1.kelime[--y_1.index] : y_2.kelime[--y_2.index]);
	
	y_1.kelime[y_1.index][0] = '\0';
	
	return gecici;
}

void odev2()
{
	int i;
	
	for (i = 0; i < kelime_sayisi; i++)
	{
		if (BUYUKHARFMI(kelimeler[i][0]) || PARANTEZAC(kelimeler[i][0]))
		{
			Ekle(kelimeler[i], 1);
		}
		else if (PARANTEZKAPAT(kelimeler[i][0]))
		{
			char *geciciyazi = (char*) malloc(sizeof(char) * 100);
			
			strcpy(geciciyazi, Cikar(1));
			
			while (!PARANTEZAC(geciciyazi[0]))
			{
				Ekle(geciciyazi, 2);
				strcpy(geciciyazi, Cikar(1));
			}
		}
		else if (bosmu(2))
		{
			char *gecici = (char*) malloc(sizeof(char) * 100);
			int carp = sayiyadonustur(kelimeler[i]);
			
			strcpy(gecici, Cikar(1));
			carp *= sayiyadonustur(&gecici[boslukindisi(gecici) + 1]);
			gecici[boslukindisi(gecici) + 1] = '\0';
			strcat(gecici, yaziyadonustur(carp));
			Ekle(gecici, 1);
		}
		else
		{
			while (y_2.index)
			{
				char *gecici = (char*) malloc(sizeof(char) * 100);
				int carp = sayiyadonustur(kelimeler[i]);
				
				strcpy(gecici, Cikar(2));
				carp *= sayiyadonustur(&gecici[boslukindisi(gecici) + 1]);
				gecici[boslukindisi(gecici) + 1] = '\0';
				strcat(gecici, yaziyadonustur(carp));
				Ekle(gecici, 1);
			}
		}
	}
}

int main()
{
	int a;
	char input[100];
	
	gets(input);
	
	sayac(input);
	
	kelimeler = (char**) malloc(sizeof(char*) * kelime_sayisi);
	
	for (a = 0; a < kelime_sayisi;) {
		kelimeler[a++]    = (char*) malloc(sizeof(char) * 100);
	}
	
	for (a = 0; a < kelime_sayisi; ){
	kelimeler[a++][0] = '\0';
	}
	
	doldur(input);
	
	y_1.index  = y_2.index = 0;
	
	y_1.kelime = (char**) malloc(sizeof(char*) * kelime_sayisi);
	y_2.kelime = (char**) malloc(sizeof(char*) * kelime_sayisi);
	
	for (a = 0; a < kelime_sayisi;){
	y_1.kelime[a++] = (char*) malloc(sizeof(char) * 100);
	}
	
	for (a = 0; a < kelime_sayisi; ){
	y_2.kelime[a++] = (char*) malloc(sizeof(char) * 100);	
	}
	
	odev2();
	
	printf("\n");
	
	for (a = 0; a < y_1.index; a++)
	{
		if (y_1.kelime[a][0])
		{
			printf("%s ", y_1.kelime[a]);
		}
	}
	
	return 0;
}
