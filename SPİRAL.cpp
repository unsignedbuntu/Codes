#include <stdio.h>
#include <conio.h>
#define SIZE 5

int main()
{
    
    int i, j = 0, ekle = 1, sat = SIZE / 2, sut = SIZE / 2, flag = 0, d[SIZE][SIZE];
    char yon = 'r';
    
    for (i = 1; i < SIZE * SIZE + 1;)
    {
        d[sat][sut] = i++;
        
        sut += (yon == 'r' ? 1 : (yon == 'l' ? -1 : 0));
        sat += (yon == 'd' ? 1 : (yon == 'u' ? -1 : 0));
        
        if ( (i%ekle==1) || i==2 )
        {   
            if (flag = !flag)  
            {
                ekle++;
            }
            
            yon = (yon == 'r' ? 'd' : (yon == 'd' ? 'l' : (yon == 'l' ? 'u' : (yon == 'u' ? 'r' : yon))));
        }
    }
    
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%3d", d[i][j]);
        }
        
        printf("\n");
    }
    
    getch();
    return 0;
}
