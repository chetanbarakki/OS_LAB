#include<stdio.h>
struct process{
    int at;
    int bt;
    int btcpy;
    int pid;
    int ct;
    int wt;
    int rt;
    int tat;
    int comp;
}a[100];
int curr_time = 0,sTat=0, sWt = 0,completed = 0,n=0;
void nonpre(){
    while(completed < n){
        int i = 0,idx = -1,bt = 1e8;
        while(i < n){
            if(a[i].at <= curr_time && a[i].comp == 0){
                if(a[i].bt < bt){
                    idx = i;
                    bt = a[i].bt;
                }
            }
            i++;
        }
        if(idx == -1){
            curr_time += 1;
        }else{
            a[idx].ct = curr_time + a[idx].bt;
            a[idx].tat = a[idx].ct - a[idx].at;
            a[idx].wt = a[idx].tat - a[idx].bt;
            curr_time = a[idx].ct;
            a[idx].comp = 1;
            completed++;
            sWt += a[idx].wt;
            sTat += a[idx].tat;
        }
    }
}
void pre(){
    while(completed < n){
        int i = 0,idx = -1,bt = 1e8;
        while(i < n){
            if(a[i].at <= curr_time && a[i].comp == 0){
                if(a[i].bt < bt){
                    idx = i;
                    bt = a[i].bt;
                }
            }
            i++;
        }
        if(idx == -1){
            curr_time += 1;
        }else{
            if(a[idx].rt == -1){
                a[idx].rt = curr_time-a[idx].at;
            }
            a[idx].ct = curr_time + 1;
            a[idx].bt--;
            if(a[idx].bt == 0){
                a[idx].tat = a[idx].ct - a[idx].at;
                a[idx].wt = a[idx].tat - a[idx].btcpy;
                a[idx].comp = 1,completed++;
                sWt += a[idx].wt;
                sTat += a[idx].tat;
            }
            curr_time = a[idx].ct;
        }
    }
}
int main(){
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i = 0 ; i< n;i++){
        printf("Enter the arrival time:");
        scanf("%d",&a[i].at);
        printf("Enter the burst time:");
        scanf("%d",&a[i].bt);
        printf("Assigning the process id: %d \n", i+1);
        a[i].pid = i+1;
        a[i].comp = 0;
        a[i].btcpy = a[i].bt;
        a[i].rt = -1;
    }
    int ch=-1;
    printf("Enter 1 for pre emptive 2 for non preemptive:");
    scanf("%d",&ch);
    switch(ch){
        case 1: pre();
            break;
        case 2: nonpre();
            break;
        default: printf("Invalid choice");
            break;
    }
    for(int i = 0; i < n; i++){
        printf("The process id: %d \n", a[i].pid);
        printf("The arrival time: %d \n",a[i].at);
        printf("The burst time: %d \n",a[i].btcpy);
        printf("The completion time: %d \n",a[i].ct);
        printf("The turnaround time: %d \n",a[i].tat);
        printf("The waiting time: %d \n",a[i].wt);
        if(ch == 1) printf("The response time: %d \n \n",a[i].rt);
    }
    printf("The average waiting time is: %f \n",(float)sWt/n);
    printf("The average turn around time is: %f",(float)sTat/n);
    return 0;
}
