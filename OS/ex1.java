import java.util.Scanner;

class Process {
    int pid;
    int btime;
    int wtime;
    int ttime;
    
    Process(int pid) {
        this.pid = pid;
        this.btime = 0;
        this.wtime = 0;
        this.ttime = 0;
    }
}

public class FCFSScheduling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter no. of process : ");
        int n = sc.nextInt();
        
        Process[] processes = new Process[n];
        
        // Get burst time for each process
        for (int i = 0; i < n; i++) {
            processes[i] = new Process(i + 1);
            System.out.print("Burst time for process P" + (i + 1) + " (in ms) : ");
            processes[i].btime = sc.nextInt();
        }
        
        // Calculate waiting time and turnaround time
        processes[0].wtime = 0;
        processes[0].ttime = processes[0].btime;
        
        for (int i = 1; i < n; i++) {
            processes[i].wtime = processes[i - 1].wtime + processes[i - 1].btime;
            processes[i].ttime = processes[i].wtime + processes[i].btime;
        }
        
        // Display scheduling table
        System.out.println("\nFCFS Scheduling");
        System.out.println("-----------------------------");
        System.out.println("Process\tB-Time\tT-Time\tW-Time");
        System.out.println("-----------------------------");
        
        for (int i = 0; i < n; i++) {
            System.out.println("P" + (i + 1) + "\t" + processes[i].btime + "\t" + 
                             processes[i].ttime + "\t" + processes[i].wtime);
        }
        System.out.println("-----------------------------");
        
        // Display GANTT Chart
        System.out.println("\nGANTT Chart");
        System.out.println("----------------------------------------");
        System.out.print("|");
        for (int i = 0; i < n; i++) {
            System.out.print(" P" + (i + 1) + " |");
        }
        System.out.println("\n----------------------------------------");
        
        // Display timeline for GANTT chart
        System.out.print("0");
        for (int i = 0; i < n; i++) {
            System.out.print("\t" + processes[i].ttime);
        }
        System.out.println("\n");
        
        // Calculate average waiting time and average turnaround time
        double totalWaitingTime = 0;
        double totalTurnaroundTime = 0;
        
        for (int i = 0; i < n; i++) {
            totalWaitingTime += processes[i].wtime;
            totalTurnaroundTime += processes[i].ttime;
        }
        
        double avgWaitingTime = totalWaitingTime / n;
        double avgTurnaroundTime = totalTurnaroundTime / n;
        
        System.out.printf("Average waiting time : %.2fms%n", avgWaitingTime);
        System.out.printf("Average turn around time : %.2fms%n", avgTurnaroundTime);
        
        sc.close();
    }
}
