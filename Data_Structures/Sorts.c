#include<stdio.h>
#include<conio.h>


void bubble(int array[],int size)
{
    int i,j,temp;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
            }   
        }       
    }
   
   
    for(i=0;i<size;i++)
        printf("%d ",array[i]);
}


//---- SELECTION SORT ALGORITMASI ----//
void selection(int array[],int size)
{
    int i,j,temp,min;
   
    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
        {       
            if(array[j]<array[min])
                min=j;
        }   
        temp=array[i];
        array[i]=array[min];
        array[min]=temp;
    }
   
    for(i=0;i<size;i++)
        printf("%d ",array[i]);   
}

//---- INSERTION SORT ALGORITMASI ----//
void insertion(int array[],int size)
{
    int i,j,temp;
   
    for(i=0;i<size;i++)
    {
        for(j=i;j>=0;j--)
        {
            if(array[j]>array[i])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }       
    }
   
    	for(i=0;i<size;i++)
        printf("%d ",array[i]);   
}



int main(int argc, char *argv[]) {
    int dizi[]={9,4,6,2,8,1};
   
   
    bubble(dizi, sizeof(dizi)/sizeof(int) );
    puts("");
    selection(dizi,sizeof(dizi)/sizeof(int) );
    puts("");
    insertion(dizi,sizeof(dizi)/sizeof(int) );
    getch();
    return 0;
}
