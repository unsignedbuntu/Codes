#include <stdio.h>
#include <conio.h>
#define SIZE 5
#define ROWCHOOSE row += (way== 'r' ? 1 : (way== 'l' ? -1 : 0))
#define COLUMNCHOOSE column += (way== 'd' ? 1 : (way== 'u' ? -1 : 0))
#define CHOOSE  way= (way== 'r' ? 'd' : (way== 'd' ? 'l' : (way== 'l' ? 'u' : (way== 'u' ? 'r' : way))))

int main()
{
    
    int i, j = 0, plus = 1, row = SIZE / 2, column = SIZE / 2, flag = 0, d[SIZE][SIZE];
    char way = 'r';
    
    for (i = 1; i < SIZE * SIZE + 1;)
    {
        d[row][column] = i++;
      
       ROWCHOOSE;
       COLUMNCHOOSE;
        
        if ( (i%plus==1) || i==2 ) 
        {   
            if (flag = !flag) //flag part works once in twice 	plus++;
            
           CHOOSE;
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
