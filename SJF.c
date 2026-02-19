#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, i, j;
    printf("Enter the numbe rof processes: ");
    scanf("%d", &n);

    int bt[n], ct[n], at[n], tat[n], wt[n];
    int done[n];

    for (i = 0; i < n; i++)
    {
        printf("enter Burst time and arrival time for process %d: ", i + 1);
        scanf("%d %d", &bt[i], &at[i]);
        done[i] = 0;
    }
    int time = 0;
    int completed = 0;

    while (completed < n)
    {
        int found = -1;

        for (i = 0; i < n; i++)
        {
            int min_bt = 99999, sel = -1;
            for (i = 0; i < n; i++)
            {
                if (at[i] <= time && !done[i] && bt[i] < min_bt)
                {
                    min_bt = bt[i];
                    sel = i;
                }
            }

            if (sel == -1)
            {

                time++;
            }
            else
            {
                ct[sel] = time + bt[sel];
                tat[sel] = ct[sel] - at[sel];
                wt[sel] = tat[sel] - bt[sel];
                time = ct[sel];
                done[sel] = 1;
                completed++;
            }
        }
    }
    int idle = 1;
    for (i = 0; i < n; i++)
    {
        if (!done[i] && at[i] <= time)
        {
            idle = 0;
            break;
        }
    }
    if (idle && completed < n)
        time++;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    return 0;
}