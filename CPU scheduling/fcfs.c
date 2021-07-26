#include<stdio.h>

int waiting_time(int proc[],int n,int wait_time[],int burst_time[])
{
    wait_time[0]=0;

    for (int i = 0; i < n; i++)
    {
        /* code */
        wait_time[i]=burst_time[i-1]+wait_time[i-1];
    }
    return 0;
    
}

int turnaroundtime(int proc[],int n,int wait_time[],int burst_time[],int tat[])
{
    int i;
    for (int i = 0; i < n; i++)
    {
        /* code */
        tat[i]=wait_time[i]+burst_time[i];

    }
    return 0;
    
}

int avgtime(int proc[],int n,int burst_time[])
{
    int tat[n],wait_time[n],total_wt=0,total_tat=0;
    
    //finding waiting time
    waiting_time(proc,n,wait_time,burst_time);

    //finding turn around time
    turnaroundtime(proc,n,wait_time,burst_time,tat);

    for (int i = 0; i < n; i++)
    {
        /* code */
        total_wt=wait_time[i]+total_wt;
        total_tat=tat[i]+total_tat;

        printf(" %d\t    %d\t\t   %d \t%d\n",i+1,burst_time[i],wait_time[i],tat[i]);



    }
    printf("Average waiting time=%f\n",(float)total_wt/(float)n);
    printf("Average turn around time =%f\n",(float)total_tat/(float)n);


    return 0;




}

int main(){
    int proc[]={1,2,3};

    int n=sizeof proc/sizeof proc[0];

    int burst_time[]={5,8,12};
    
    avgtime(proc,n,burst_time);

    return 0;
    
    }