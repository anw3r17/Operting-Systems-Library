#include<stdio.h>
#include<string.h> 
main()
{
int i=0,pno[10],burr[10],n,wt[10],temp=0,j,tat[10];
float sum,at;
printf("\n Enter the no of process ");
scanf("\n %d",&n);
printf("\n Enter the burst time of each process");
for(i=0;i<n;i++)
{
printf("\n p%d",i);
scanf("%d",&burr[i]);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(burr[i]>burr[j])
{
temp=burr[i];
burr[i]=burr[j];
burr[j]=temp;
temp=pno[i];
pno[i]=pno[j];
pno[j]=temp;
}
}
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=burr[i-1]+wt[i-1];
sum=sum+wt[i];
}
printf("\n process no \t burst time\t waiting time \t turn around time\n");
for(i=0;i<n;i++)
{
tat[i]=burr[i]+wt[i];
at+=tat[i];
printf("\n p%d\t\t%d\t\t%d\t\t%d",i,burr[i],wt[i],tat[i]);
}
printf("\n\n\t Average waiting time%f\n\t Average turn around time%f", sum, at);
}
