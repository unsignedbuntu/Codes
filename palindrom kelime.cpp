#include<stdio.h>
#include<conio.h>

int main()
{
    int a, b, c;
    char kelime[100];
    printf("kelime girin: ");
    gets(kelime);

    for(a = 0; kelime[a] != '\0'; a++) ; // a uzunluk
    
    b = ((a % 2) == 0) ? (a / 2) : ((a + 1) / 2); //uzunlugun yarisi 
    c = 0; //kontrol
    for (int i = 0; i < b; i++)
    {
        if (kelime[i] == kelime[a - i - 1])
        {
            c++;
        }
    }
    
    if(c == b)
        printf("palindrom kelime girdiniz");
    else
        printf("palindrom kelime girmediniz");

    getch();
    return 0;
}
