import java.util.*;

class Process implements Comparable<Process> {
    String pid;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    
    public Process(String pid, int burstTime) {
        this.pid = pid;
        this.burstTime = burstTime;
        this.waitingTime = 0;
        this.turnaroundTime = 0;
    }
    
    @Override
    public int compareTo(Process other) {
        if (this.burstTime == other.burstTime) {
            return this.pid.compareTo(other.pid);
        }
        return this.burstTime - other.burstTime;
    }
}

public class SJFScheduling {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter no. of process : ");
        int n = sc.nextInt();
        
        List<Process> processes = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            System.out.print("Burst time for process P" + (i + 1) + " (in ms) : ");
            int burstTime = sc.nextInt();
            processes.add(new Process("P" + (i + 1), burstTime));
        }
        
        Collections.sort(processes);
        
        calculateWaitingAndTurnaroundTime(processes);
        
        displaySchedulingTable(processes);
        
        displayGanttChart(processes);
        
        displayAverageMetrics(processes);
        
        sc.close();
    }
    
    private static void calculateWaitingAndTurnaroundTime(List<Process> processes) {
        int currentTime = 0;
        
        for (Process p : processes) {
            p.waitingTime = currentTime;
            p.turnaroundTime = currentTime + p.burstTime;
            currentTime += p.burstTime;
        }
    }
    
    private static void displaySchedulingTable(List<Process> processes) {
        System.out.println("\nSJF Scheduling");
        System.out.println("----------------------------");
        System.out.println("Process\tB-Time\tT-Time\tW-Time");
        System.out.println("----------------------------");
        
        for (Process p : processes) {
            System.out.println(p.pid + "\t" + p.burstTime + "\t" + p.turnaroundTime + "\t" + p.waitingTime);
        }
        
        System.out.println("----------------------------");
    }
    
    private static void displayGanttChart(List<Process> processes) {
        System.out.println("\nGANTT Chart");
        System.out.println("-----------------------------------------------");
        
        System.out.print("| ");
        for (Process p : processes) {
            System.out.print(p.pid + " | ");
        }
        System.out.println();
        System.out.println("-----------------------------------------------");
        
        int currentTime = 0;
        System.out.print(currentTime);
        for (Process p : processes) {
            currentTime += p.burstTime;
            System.out.print("\t" + currentTime);
        }
        System.out.println();
    }
    
    private static void displayAverageMetrics(List<Process> processes) {
        double totalWaitingTime = 0;
        double totalTurnaroundTime = 0;
        
        for (Process p : processes) {
            totalWaitingTime += p.waitingTime;
            totalTurnaroundTime += p.turnaroundTime;
        }
        
        double avgWaitingTime = totalWaitingTime / processes.size();
        double avgTurnaroundTime = totalTurnaroundTime / processes.size();
        
        System.out.printf("Average waiting time : %.2fms\n", avgWaitingTime);
        System.out.printf("Average turn around time : %.2fms\n", avgTurnaroundTime);
    }
}
