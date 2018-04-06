/*Ques. 4.  Consider a scheduling approach which is non pre-emptive similar to shortest job next in nature. 
The priority of each job is dependent on its estimated run time, and also the amount of time it has spent waiting. 
Jobs gain higher priority the longer they wait, which prevents indefinite postponement. 
The jobs that have spent a long time waiting compete against those estimated to have short run times. 
The priority can be computed as : Priority = 1+ Waiting time / Estimated run time 
Using the data given below compute the waiting time and turnaround time for each process and average waiting time and average turnaround time. 
 
Process Arrival time Burst time 
P1 0 20 P2 5 36 P3 13 19 P4 17 42 
 */
 #include<stdio.h>
#include<conio.h>
#include<stdbool.h>
int j,i,k,n,arv[10],burst[10],wait[10],tat[10],prr[10];

 void main()
 {
 	int k;
 	printf("\nEnter the number of requirements:\t");
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		printf("Enter the arival time of process p%d: \t",i+1);
		scanf("%d",&k);
		if(k==0)
		{
		printf("zero not allowed\n");
		printf("Re-enter the arrival time:\t");
		scanf("%d",&arv[i]);
		}
		else
			arv[i]=k;
		printf("Enter the burst time of the proecss:\t");
		scanf("%d",&burst[i]);
		
	}
	int j,temp=0;

	//Priority = 1+ Waiting time / Estimated run time
	for(i=0;i<n;i++)
	{
		bool x = false;
		int k;
		k=1+(wait[i]/burst[i]);
		for(j=0;j<i;j++)
		{
			if(k==prr[j])
			x = true;
		}
		if(x)
		prr[i]=k+i;
		else
		prr[i]=k;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
		
		if(prr[i]>prr[j])
		{
			temp=prr[i];
			prr[i]=prr[j];
			prr[j]=temp;
			
			temp=burst[i];
			burst[i]=burst[j];
			burst[j]=temp;
			
			temp=arv[i];
			arv[i]=arv[j];
			arv[j]=temp;
			
		}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\npriority:%d",prr[i]);
	}
	tatm();waitingtime();avgwait();avgtat();
}
void waitingtime()
{
	int temp=0;
	wait[0]=0;
	printf("Waiting time of process p1 is:0");
	for(i=1;i<n;i++)
	{
		
		for(j=0;j<i;j++)
		{
			temp+=burst[j];
			
		}
		temp+=arv[0];
		printf("\nWaiting time of process p%d:%d",i+1,temp-arv[i]);
		wait[i]=temp-arv[i];
		temp=0;
		
	}
}
void avgwait()
{
	int avg=0;
	for(i=0;i<n;i++)
	{
		avg+=wait[i];
	}
	printf("\nAverage waiting time is:%d",avg/n);
	
}
void avgtat()
{
	int	avg=0;
	for(i=0;i<n;i++)
	{
		avg+=tat[i];
	}
	printf("\nAverage TAT is:%d",avg/n);
	
}	
void tatm()
{
	for(i=0;i<n;i++)
	{
		printf("\nTurnAroundTime of the process p%d is:%d",i+1,wait[i]+burst[i]);
		tat[i]=wait[i]+burst[i];
	}
	
}
