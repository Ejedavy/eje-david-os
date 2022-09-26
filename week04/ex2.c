#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int dotprod(int u[], int v[], int start, int end)
{
    int result = 0;

    for (int i = start; i <= end; i++)
    {
        result += u[i] * v[i];
    }

    return result;
}

int main()
{
    srand(time(NULL));

    int u[120];
    int v[120];
    for (int i = 0; i < 120; i++)
    {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }

    int n;
    scanf("%d", &n);
    FILE* output = fopen("temp.txt", "w");
    for (int i = 0; i < n; i++)
    {
        int id = fork();
        if (id == 0)
        {
            int start = (120 / n) * i;
            int end = (120 / n) * i + (120 / n) - 1;
            int c_i = dotprod(u, v, start, end);
            fprintf(output, "%d\n", c_i);
            exit(0);
        }
    }
    fclose(output);
    for (int i = 0; i < n; i++)
        wait(NULL);
    FILE* input = fopen("temp.txt", "r");
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int c;
        fscanf(input, "%d", &c);
        result += c;
    }
    fclose(input);
    printf("Answer is: %d\n", result);
    return EXIT_SUCCESS;
}