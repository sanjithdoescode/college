#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
};

int main() {
    int n, i, time_slice, current_time = 0, completed = 0;
    float avg_wait = 0, avg_tat = 0;

    printf("Enter no. of process : ");
    scanf("%d", &n);

    struct Process p[n];
    int gantt_p[100]; // To store process order for Gantt Chart
    int gantt_time[101]; // To store time markers for Gantt Chart
    int g_idx = 0;

    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Burst time for process P%d : ", p[i].id);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }

    printf("Enter the time slice (in ms) : ");
    scanf("%d", &time_slice);

    gantt_time[0] = 0;

    // Scheduling Logic
    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                gantt_p[g_idx] = p[i].id;
                
                if (p[i].remaining_time > time_slice) {
                    current_time += time_slice;
                    p[i].remaining_time -= time_slice;
                } else {
                    current_time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    p[i].turnaround_time = current_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    completed++;
                }
                
                g_idx++;
                gantt_time[g_idx] = current_time;
            }
        }
    }

    // Display Gantt Chart
    printf("\nRound Robin Scheduling\n");
    printf("GANTT Chart\n");
    printf("----------------------------------------------------------------\n");
    for (i = 0; i < g_idx; i++) {
        printf(" P%d |", gantt_p[i]);
    }
    printf("\n----------------------------------------------------------------\n");
    for (i = 0; i <= g_idx; i++) {
        printf("%-5d", gantt_time[i]);
    }
    
    // Display Process Table
    printf("\n\n------------------------------\n");
    printf("Process  Burst  Trnd  Wait\n");
    printf("------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t %-6d %-5d %-5d\n", p[i].id, p[i].burst_time, p[i].turnaround_time, p[i].waiting_time);
        avg_wait += p[i].waiting_time;
        avg_tat += p[i].turnaround_time;
    }
    printf("------------------------------\n");

    printf("Average waiting time : %.2f ms\n", avg_wait / n);
    printf("Average turn around time : %.2f ms\n", avg_tat / n);

    return 0;
}
