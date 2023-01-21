#include<stdio.h>
#include<stdlib.h>
int main()
{
int i=1, j=1, noframes=10, x, x1=10,k;
printf("Enter number of frames is\n");
scanf("%d",&noframes);
//getch();
while(noframes>10)
{
printf("\nSending frames is %d",i);
x=rand()%10;
if(x%10==0)
{ 
     for(k=1;k<2;k++)
        {
         printf("\nwaiting for %d seconds\n",k);
         sleep(k);
        }
     printf("\nSending frames is %d\n",i);
     x=rand()%10;
}
 printf("\nAck for frames %d\n",j);
noframes =noframes-1;
i++;
j++;
}
printf("\nEnd of stop and wait protocol\n");
return 0;
}

