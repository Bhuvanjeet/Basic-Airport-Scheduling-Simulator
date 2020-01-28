//implementation in c 
#include <stdio.h> 
#include <conio.h> 
#include<math.h> 
#include<string.h> 
int wt[100],bt[100],at[100],tat[100],n,p[100]; 
float awt[5],atat[5]; 
void create_file_csv(char *filename,int a[][2],int n,int m)
{
	printf("\n Creating %s.csv file",filename); 
	FILE *fp; 
	int i,j; 
	filename=strcat(filename,".csv"); 
	fp=fopen(filename,"w+"); 
	fprintf(fp,"FCFS, SJF, RR, SRTF, Innovative Algo"); 
	for(i=0;i<m;i++) 
	{
		fprintf(fp,"\n%d",i+1); 
		for(j=0;j<n;j++) 
		fprintf(fp,",%d ",a[i][j]);
	}
	fclose(fp); printf("\n %sfile created",filename);
}	
void input()
{
	printf("Enter Number of airoplanes to be scheduled:");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
		p[i]=i+1;
	for(i=0;i<n;i++)
	{
		printf("Enter time after which airplane %d should depart :",i+1);
		scanf("%d",&bt[i]);
		printf("Enter Arrival Time of airplane %d:",i+1);
		scanf("%d",&at[i]);
	}
	for(i=0;i<5;i++)
	{
		awt[i]=0.0;
		atat[i]=0.0;
	}
}
void changeArrival()
{
	int a=at[0];
	int i;
	for(i=0;i<n;i++)
	{
		if(at[i]<a)
		a=at[i];
	}
	if(a!=0)
	{
		for(i=0;i<n;i++)
			at[i]=at[i]-a;
	}
}
void fcfs()
{
	wt[0]=0;
	atat[0]=tat[0]=bt[0];
	int btt=bt[0];
	int i;
	for(i=1;i<n;i++)
	{
		wt[i]=btt-at[i];
		btt+=bt[i];
		awt[0]+=wt[i];
		tat[i]= wt[i]+bt[i];
		atat[0]+=tat[i];
	}
	atat[0]/=n;
	awt[0]/=n;
	printf("Airplane\tA.T. of airplane\tTime for departure \tW.T. foe airplane\tT.A.T. for airplane\n");
	for(i=0;i<n;i++)
	{
		printf("%3d\t\t%3d\t\t\t%3d\t\t\t\t%3d\t\t\t\t%4d\n",i+1,at[i],bt[i],wt[i],tat[i]);
	}
}
void innovative()
{
	int bt1[n],i,j,temp,tq;
	int b[n];
	float twt=0,ttat=0;
	for(i=0;i<n;i++)
		bt1[i]=bt[i];
	for(i=0;i<n;i++)
		b[i]=bt[i];
	int num=n;
	int time=0;
	int max;
	int sum,t,a,ap=0;
	while(num>0)
	{
		a=0;
		max=0;
		sum=0;
		t=0;
//sorting in ascending order
		for(i=0;i<n;i++)
		{	
			for(j=0;j<n;j++)
			{
				if(b[i]<b[j] && at[i]<=time)
				{
					temp=p[j];
					p[j]=p[i];
					p[i]=temp;
					temp=at[j];
					at[j]=at[i];
					at[i]=temp;
					temp=b[j];
					b[j]=b[i];
					b[i]=temp;
					temp=bt1[j];
					bt1[j]=bt1[i];
					bt1[i]=temp;
				}
			}
		}
	for(i=0;i<n;i++)
	{
		if(at[i]<=time && b[i]!=0)
		{
			a++;
			if(b[i]>max)
				max=b[i];
			sum+=b[i];
		}
	}
	if(a!=ap)
	{
		tq=sqrt((sum/a)*max);
		ap=a;
	}
	for(i=0;i<n;i++)
	{
		if(at[i]<=time && b[i]!=0)
		{
			if(b[i]<tq)
			{
				t+=b[i];
				b[i]=0;
			}
			else
			{
				t+=tq;
				b[i]-=tq;
			}
			if(b[i]==0)
			{
				wt[i]=(time+t)-bt1[i];
				tat[i]=time+t;
				num--;
			}
		}
	}
	time+=t;
}
printf("Airplane\tWaitingTime for airplane\tTurnAroundTime for airplane\n");
for(j=1;j<=n;j++)
{
	for(i=0;i<n;i++)
	{
		if(j==p[i])
		printf("Airplane %d\t\t%d\t\t\t%d\n",p[i],wt[i],tat[i]);
	}
}
for(i=0;i<n;i++)
	twt=twt+wt[i];
awt[4]=twt/n;
for(i=0;i<n;i++)
	ttat=ttat+tat[i];
atat[4]=ttat/n;}
void rr()
{
	int i, total = 0, x, counter = 0, time_quantum;
	int wait_time = 0, turnaround_time = 0, temp[100];
	x=n;
	for(i = 0; i < n; i++)
	{
		temp[i] = bt[i];
	}
	printf("\nEnter Time Quantum i.e. time after which departure should occur:\t");
	scanf("%d", &time_quantum);
	printf("\nAirplane\t\tTime after airplane must depart\t Turnaround Time for airplane\t Waiting Time of airplane\n");
	for(total = 0, i = 0; x != 0;)
	{
		if(temp[i] <= time_quantum && temp[i] > 0)
		{
			total = total + temp[i];
			temp[i] = 0;
			counter = 1;
		}
		else if(temp[i] > 0)
		{
			temp[i] = temp[i] - time_quantum;
			total = total + time_quantum;
		}
		if(temp[i] == 0 && counter == 1)
		{ 
			x--;
			printf("Airplane[%d]\t\t%d\t\t\t\t %d\t\t\t\t\t %d\n", i + 1, bt[i], total - at[i], total - at[i] - bt[i]);
			wait_time = wait_time + total - at[i] - bt[i];
			turnaround_time = turnaround_time + total - at[i];
			counter = 0;
		}
		if(i == n - 1)
		{
			i = 0;
		}
		else if(at[i + 1] <= total)
		{
			i++;
		else
		{
			i = 0;
		}
		}
		awt[2] = wait_time * 1.0 / n;
		atat[2] = turnaround_time * 1.0 / n;
	}
void display(int c)
{
	printf("Average Waiting Time: %f\nAverage Turn Around Time:%f",awt[c-1],atat[c-1]);
}
}
void sjf()
{
	float wavg=0,tavg=0,tsum=0,wsum=0;
	int i,j,temp,sum=0,ta=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(at[i]<at[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=at[j];
at[j]=at[i];
at[i]=temp;
temp=bt[j];
bt[j]=bt[i];
bt[i]=temp;
}
}
} int btime=0,min,k=1;
for(j=0;j<n;j++)
{ 
btime=btime+bt[j];
min=bt[k];
for(i=k;i<n;i++)
{
if(btime>=at[i] && bt[i]<min)
{ 
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=at[k];
at[k]=at[i];
at[i]=temp;
temp=bt[k];
bt[k]=bt[i];
bt[i]=temp;
}
}
k++; }
wt[0]=0;
for(i=1;i<n;i++)
{ sum=sum+bt[i-1];
wt[i]=sum-at[i];
wsum=wsum+wt[i];
}
awt[1]=(wsum/n);
for(i=0;i<n;i++)
{ ta=ta+bt[i];
tat[i]=ta-at[i];
tsum=tsum+tat[i];
}
atat[1]=(tsum/n);
printf("Airplane\tA.T. of airplane\tTime after which airplane must depart\tW.T. of airplane \tT.A.T. of airplane\n");
for(i=0;i<n;i++)
{
printf("%3d\t\t%3d\t\t\t\t%3d\t\t\t\t%3d\t\t\t\t%4d\n",i+1,at[i],bt[i],wt[i],tat[i]);
}
}
int main(){
printf("Welcome to Airport Scheduling Simulator:\n\n");
input();
int c,choice;
changeArrival();
printf("Choice\tAlgorithm used\n1\tFCFS Algorithm\n2\tSJF Algorithm\n3\tRound robin\n4\tOur innovative algorithm\n");
do
{
printf("Enter your choice from the above table");
scanf("%d",&c);
switch(c)
{
case 1:fcfs();
break;
case 2:sjf();
break;
case 3:rr();
break;
case 4:innovative();
break;
default: printf("Please enter choice from 1 to 4 only\n"); 
break; 
}
display(c); 
printf("\n\nEnter 1 to continue 0 to stop"); 
scanf("%d",&choice);
}
while(choice==1); 
int a[5][2],i; 
for(i=0;i<5;i++) 
{
a[i][0]=awt[i]; 
a[i][1]=atat[i]; 
}
create_file_csv("schedule",a,5,2); 
}
