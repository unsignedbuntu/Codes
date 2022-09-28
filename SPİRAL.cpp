#include <stdio.h>
#include <conio.h>

int main()
{
    int x = 5;
    
    int i, j = 0, ekle = 1, sat = x / 2, sut = x / 2, flag = 0, d[x][x];
    char yon = 'r';
    
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            d[i][j] = 0;
        }
    }
    
    for (i = 1, j = 0; i < x * x + 1; i++, j--)
    {
        d[sat][sut] = i;
        
        sut += (yon == 'r' ? 1 : (yon == 'l' ? -1 : 0));
        sat += (yon == 'd' ? 1 : (yon == 'u' ? -1 : 0));
        
        if (!j)
        {
            j = ekle;
            // USTA GELDI
            if (flag = !flag) // ADAM KAZANDI
            {
                ekle++;
            }
            
            yon = (yon == 'r' ? 'd' : (yon == 'd' ? 'l' : (yon == 'l' ? 'u' : (yon == 'u' ? 'r' : yon))));
        }
    }
    
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            printf("%5d", d[i][j]);
        }
        
        printf("\n");
    }
    
    getch();
    return 0;
}
