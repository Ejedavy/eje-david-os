#include <stdio.h>
#include <stdbool.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{

    int n, quantum_size;
    double average_turnaroud_time = 0, average_waiting_time = 0;

    printf("How many processes are to be executed\n");
    scanf("%d", &n);


    printf("Enter Quantum size: ");
    scanf("%d", &quantum_size);

    int arrival_time[n];
    int burst_time[n];
    int turn_around_time[n];
    int execution_time[n];
    int waiting_time[n];
    int burst_time_finish[n];
    bool executed[n];


    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);

        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &burst_time[i]);

        burst_time_finish[i] = burst_time[i];
        executed[i] = false;
    }

    int current_time = arrival_time[0], finished_processes = 0;
    int i = 0;
    while (finished_processes != n)
    {
        if (executed[i] == false && arrival_time[i] <= current_time)
        {
            if (burst_time[i] > quantum_size)
            {
                current_time += quantum_size;
                burst_time[i] -= quantum_size;
            }
            else
            {
                executed[i] = true;
                current_time += burst_time[i];
                execution_time[i] = current_time;

                turn_around_time[i] = execution_time[i] - arrival_time[i];
                waiting_time[i] = turn_around_time[i] - burst_time_finish[i];

                average_turnaroud_time += (double)turn_around_time[i] / n;
                average_waiting_time += (double)waiting_time[i] / n;
                finished_processes++;
            }
        }
        i = (i + 1) % n;
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

    printf("Average Turnaround Time: %f\n", average_turnaroud_time);
    printf("Average Waiting Time: %f\n", average_waiting_time);
}