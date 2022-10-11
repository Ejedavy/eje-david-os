#include <stdio.h>

#define MAX_PROCESSES 20

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int arrival_time[MAX_PROCESSES];
    int burst_time[MAX_PROCESSES];
    int turn_around_time[MAX_PROCESSES];
    int execution_time[MAX_PROCESSES];
    int waiting_time[MAX_PROCESSES];

    int n;
    double average_turn_around_time = 0, average_waiting_time = 0;

    printf("How many processes are to be executed:\n");
    scanf("%d", &n);
    printf("Enter Arrival Time and Burst Time:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival Time of process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);

        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("\n");

    int current_time = arrival_time[0];
    for (int i = 0; i < n; i++)
    {
        current_time = max(current_time, arrival_time[i]);
        current_time += burst_time[i];
        execution_time[i] = current_time;
        turn_around_time[i] = execution_time[i] - arrival_time[i];
        waiting_time[i] = turn_around_time[i] - burst_time[i];
        average_turn_around_time += (double)turn_around_time[i] / n;
        average_waiting_time += (double)waiting_time[i] / n;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Arival Time: %d\n", arrival_time[i]);
        printf("Burst Time: %d\n", burst_time[i]);
        printf("Turnaround Time: %d\n", turn_around_time[i]);
        printf("Waiting Time: %d\n", waiting_time[i]);
        printf("Execution Time: %d\n\n", execution_time[i]);
    }

    printf("Average Turnaround Time: %f\n", average_turn_around_time);
    printf("Average Waiting Time: %f\n", average_waiting_time);
}