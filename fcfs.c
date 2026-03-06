#include<stdio.h>
struct process{
    int at;
    int bt;
    int pid;
    int ct;
    int wt;
    int tat;
    int comp;
}a[100];
void main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i = 0 ; i< n;i++){
        printf("Enter the arrival time:");
        scanf("%d",&a[i].at);
        printf("Enter the burst time:");
        scanf("%d",&a[i].bt);
        printf("Assigning the process id: %d \n", i+1);
        a[i].pid = i+1;
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i].at > a[j].at){
                struct process temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    int curr_time = 0,sTat=0, sWt = 0;
    for(int i = 0; i < n; i++){
        if(curr_time < a[i].at){
            curr_time = a[i].at;
        }
        a[i].ct = curr_time + a[i].bt;
        a[i].tat = a[i].ct - a[i].at;
        a[i].wt = a[i].tat-a[i].bt;
        curr_time = a[i].ct;
        sTat += a[i].tat;
        sWt += a[i].wt;
    }
    for(int i = 0; i < n; i++){
        printf("The process id: %d \n", a[i].pid);
        printf("The arrival time: %d \n",a[i].at);
        printf("The burst time: %d \n",a[i].bt);
        printf("The turnaround time: %d \n",a[i].tat);
        printf("The waiting time: %d \n \n",a[i].wt);
    }
    printf("The average waiting time is: %f \n",(float)sWt/n);
    printf("The average turn around time is: %f",(float)sTat/n);

}
