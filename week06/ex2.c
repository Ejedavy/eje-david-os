#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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
    bool executed[MAX_PROCESSES];

    int n, minimum_arrival_time = INT_MAX;
    double average_turnaround_time = 0, average_waiting_time = 0;

    printf("Enter amount of processes to execute:\n");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Arrival Time of process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);

        printf("Burst Time of process %d: ", i + 1);
        scanf("%d", &burst_time[i]);

        executed[i] = false;
        if (arrival_time[i] < minimum_arrival_time)
            minimum_arrival_time = arrival_time[i];
    }

    printf("\n");

    int current_time = minimum_arrival_time;
    int i = 0;
    while (1)
    {
        current_time = max(current_time, arrival_time[i]);

        int index = -1, minimum_burst_time = INT_MAX;

        for (int j = 0; j < n; j++)
        {
            if (arrival_time[i] <= current_time && !executed[j] && burst_time[j] < minimum_burst_time && arrival_time[j] <= current_time)
            {
                index = j;
                minimum_burst_time = burst_time[j];
            }
        }

        if (index == -1)
            continue;

        executed[index] = true;
        current_time += burst_time[index];
        execution_time[index] = current_time;

        turn_around_time[index] = execution_time[index] - arrival_time[index];
        waiting_time[index] = turn_around_time[index] - burst_time[index];

        average_turnaround_time += (double)turn_around_time[index] / n;
        average_waiting_time += (double)waiting_time[index] / n;

        i++;
        if (i >= n)
            break;
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

    printf("Average Turnaround Time: %f\n", average_turnaround_time);
    printf("Average Waiting Time: %f\n", average_waiting_time);
}