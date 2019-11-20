/**
 * First come first serve CPU scheduling algorithm.
 */

#include <stdio.h>

void compute_waiting_time(int n, int bt[], int wt[])
{
    wt[0] = 0; // waiting time for 1st process is zero
    for (size_t i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
}

void compute_turnaround_time(int n, int bt[], int wt[], int tat[])
{
    for (size_t i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];
}

void compute_average_time(int processes[], int n, int bt[])
{
    int wt[n], tat[n], totalWt = 0, totalTat = 0;

    compute_waiting_time(n, bt, wt);
    compute_turnaround_time(n, bt, wt, tat);

    for (size_t i = 0; i < n; i++)
        totalWt += wt[i];
    for (size_t i = 0; i < n; i++)
        totalTat += tat[i];

    float avgWt = (float)totalWt / (float)n;
    float avgTat = (float)totalTat / (float)n;

    printf("Processes   Burst time   Waiting time   Turn around time\n");
    for (int i = 0; i < n; i++)
    {
        printf("    %d\t", processes[i]);
        printf("\t%d\t", bt[i]);
        printf("\t%d\t", wt[i]);
        printf("\t%d\n", tat[i]);
    }
    printf("Total waiting time = %d\n", totalWt);
    printf("Total turn around time = %d\n", totalTat);
    printf("Average waiting time = %.2f\n", avgWt);
    printf("Average turn around time = %.2f\n", avgTat);
}

int main()
{
    int processes[] = {1, 2, 3}; // process IDs
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {10, 5, 8}; // burst time of the processes

    compute_average_time(processes, n, burst_time);

    return 0;
}
