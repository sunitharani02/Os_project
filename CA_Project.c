#include<stdio.h> 
int main() 
{ 
  int count,m;
  int time,remains;
  int flag=0,timequantum=10; 
  int waitingtime=0,turnaroundtime=0,arrivaltime[10],bursttime[10],ad[10]; 
  printf("\nEnter the entire number of Processes: "); 
  scanf("%d",&m); //Insert the entire number of processes.
  remains=m; 
  for(count=0;count<m;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Number %d :",count+1); .
    scanf("%d",&arrivaltime[count]); //Insert the arrival time for the given number of processes.
    scanf("%d",&bursttime[count]);  //Insert the burst time for the given number of processes
    ad[count]=bursttime[count]; 
  } 
  printf("Enter Time Quantum:%d\t",timequantum); //Displaying the time quantum of the entire process.
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remains!=0;) 
  { 
    if(ad[count]<=timequantum && ad[count]>0) 
    { 
      time+=ad[count]; 
      ad[count]=0; 
      flag=1; 
    } 
    else if(ad[count]>0) 
    { 
      ad[count]-=timequantum; 
      time+=timequantum; 
    } 
    if(ad[count]==0 && flag==1) 
    { 
      remains--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-arrivaltime[count],time-arrivaltime[count]-bursttime[count]); 
      waitingtime+=time-arrivaltime[count]-bursttime[count]; //Calculating the average waiting time.
      turnaroundtime+=time-arrivaltime[count]; //Calculating the average turnaround time.
      flag=0; 
    } 
    if(count==m-1) 
    {
	  count=0; 
    }
	else if(arrivaltime[count+1]<=time) 
    {
	  count++; 
    }
	else
    {
	  count=0; 
    }
  } 
  printf("\nAverage Waiting Time= %f\n",waitingtime*1.0/m); //Displaying the average waiting time of the entire process.
  printf("Average Turnaround Time = %f",turnaroundtime*1.0/m); //Displaying the average turn around time of the entire process.
  return 0; 
}
