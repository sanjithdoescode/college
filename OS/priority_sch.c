#include <stdio.h>
#include <string.h>

// 1. Define the structure for a process
struct process {
    char pid[10];
    int btime;
    int pri;
    int wtime;
    int ttime;
};

int main() {
    int n, i, j;
    float total_wtime = 0, total_ttime = 0;
    struct process p[20], temp;

    // 2. Get the number of processes
    printf("Enter no. of process : ");
    scanf("%d", &n);

    // 3. Obtain burst time and priority for each process
    for (i = 0; i < n; i++) {
        sprintf(p[i].pid, "P%d", i + 1);
        printf("Burst time for process %s (in ms) : ", p[i].pid);
        scanf("%d", &p[i].btime);
        printf("Priority for process %s : ", p[i].pid);
        scanf("%d", &p[i].pri);
    }

    // 4. Sort processes according to priority (Ascending)
    // Note: Stable sorting or maintaining original index ensures FCFS for ties
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].pri > p[j+1].pri) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // 5 & 6. Compute waiting time and turnaround time
    p[0].wtime = 0;
    p[0].ttime = p[0].btime;
    
    for (i = 1; i < n; i++) {
        p[i].wtime = p[i-1].wtime + p[i-1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
    }

    // 7. Compute averages
    for (i = 0; i < n; i++) {
        total_wtime += p[i].wtime;
        total_ttime += p[i].ttime;
    }

    // 8. Display tabular output
    printf("\nPriority Scheduling\n");
    printf("--------------------------------------------------\n");
    printf("Process\tB-Time\tPriority\tT-Time\tW-Time\n");
    printf("--------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].btime, p[i].pri, p[i].ttime, p[i].wtime);
    }
    printf("--------------------------------------------------\n");

    // 9. Display GANTT Chart
    printf("\nGANTT Chart\n");
    printf("----------------------------------------------------\n|");
    for (i = 0; i < n; i++) {
        printf(" %s |", p[i].pid);
    }
    printf("\n----------------------------------------------------\n");
    
    printf("0");
    for (i = 0; i < n; i++) {
        printf("   %d", p[i].ttime);
    }

    // 10. Display averages
    printf("\n\nAverage waiting time : %.2fms", total_wtime / n);
    printf("\nAverage turn around time : %.2fms\n", total_ttime / n);

    return 0;
}
