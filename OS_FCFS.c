#include <stdio.h>

struct Process
{
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};

void calculateTimes(struct Process processes[], int n)
{
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;
    processes[0].completionTime = processes[0].burstTime;

    for (int i = 1; i < n; i++)
    {
        processes[i].waitingTime = processes[i - 1].completionTime - processes[i].arrivalTime;
        if (processes[i].waitingTime < 0)
        {
            processes[i].waitingTime = 0;
        }
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        processes[i].completionTime = processes[i].arrivalTime + processes[i].turnaroundTime;
    }
}

void displayGanttChart(struct Process processes[], int n)
{
    printf("\nGantt Chart:\n");
    printf("| ");
    for (int i = 0; i < n; i++)
    {
        printf("P%d (%d) | ", i + 1, processes[i].completionTime);
    }
    printf("\n");
}
void displayTimes(struct Process processes[], int n)
{
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].arrivalTime, processes[i].burstTime,
               processes[i].waitingTime, processes[i].turnaroundTime, processes[i].completionTime);
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    calculateTimes(processes, n);
    displayGanttChart(processes, n);
    displayTimes(processes, n);

    // Calculate and display average waiting and turnaround times
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printf("\nAverage Waiting Time: %.2f milliseconds\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f milliseconds\n", avgTurnaroundTime);

    return 0;
}