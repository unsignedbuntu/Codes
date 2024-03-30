#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
srand(time(0));

int dizi[20]={0},a=0,b,eb,temp;

for(a=0;a<20;a++)	
{
 dizi[a]=rand()%99+1;

 a==19 ?	printf("%d\n\n",dizi[a]) : printf("%d-",dizi[a]);
}	

int *p=(int *) malloc(20*sizeof(int));

 
for(a=0;a<20;a++)
 {
	*(p+a)=dizi[a];	
 }

	eb=*p;

	for(a=0;a<20;a++)
	{
		for(b=a+1;b<20;b++)
		{
			if(*(p+a) < *(p+b) )
			{
			temp=*(p+b);
			*(p+b)=*(p+a);
			*(p+a)=temp;
			}
		}
	}
	
	for(a=0;a<20;a++)
	{
	a==19 ? printf("%d",*(p+a)) :	printf("%d>",*(p+a) );	
	}

free(p);
	
getch();
return 0;	
}
