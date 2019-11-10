#include <stdio.h>

/**
 * Safety Algorithm: checks if system is in a safe state
 * 
 * @param int m: number of resource types
 * @param int n: number of processes
 * @param int available[m]: number of available resources of each type
 * @param int max[n][m]: maximum demand of each process
 * @param int allocation[n][m]: number of resources of each type 
 *                              currently allocated to each process
 * @param int need[n][m]: remaining resource need of each process
 */
int is_safe(int m, int n, int available[], int max[n][m],
            int allocation[n][m])
{
    int safe_seq[n];
    int finish[n];
    int need[n][m];
    int work[m];

    for (int i = 0; i < n; i++)
        finish[i] = 0;

    for (int i = 0; i < m; i++)
        work[i] = available[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    int count = 0;
    while (count < n)
    {
        int found = 0;
        for (int p = 0; p < n; p++)
        {
            if (!finish[p])
            {
                int j;
                for (j = 0; j < m; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == m)
                {
                    for (int k = 0; k < m; k++)
                        work[k] += allocation[p][k];
                    safe_seq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
        {
            printf("not safe\n");
            return 0;
        }
    }
    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", safe_seq[i]);
    printf("\n");
    return 1;
}

int main(int argc, char const *argv[])
{
    int processes[] = {0, 1, 2, 3, 4};
    int available[] = {3, 3, 2};
    const int n = sizeof processes / sizeof processes[0];
    const int m = sizeof available / sizeof available[0];
    int max[][m] = {{7, 5, 3},
                    {3, 2, 2},
                    {9, 0, 2},
                    {2, 2, 2},
                    {4, 3, 3}};
    int allocation[][m] = {{0, 1, 0},
                           {2, 0, 0},
                           {3, 0, 2},
                           {2, 1, 1},
                           {0, 0, 2}};
    is_safe(m, n, available, max, allocation);
    return 0;
}
