#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter no of processes:";
    cin >> n;
    int at[n], bt[n], ct[n], tat[n], wt[n] = {0};
    float tatsum = 0, wtsum = 0;
    int preburst = 0;
    int visit[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the arrival time for the process:"
             << "\n";
        cin >> at[i];
        cout << "Enter the burst time of the process:"
             << "\n";
        cin >> bt[i];
    }

    int min = 1e5;
    int minburst;
    for (int i = 0; i < n; i++)
    {
        if (min > bt[i] && visit[i] == 0)
        {
            min = bt[i];
            minburst = i;
        }
    }
    ct[minburst] = bt[minburst] + at[minburst];
    visit[minburst] = 1;
    preburst = minburst;
    for (int i = 1; i < n; i++)
    {
        min = 1e5;
        for (int j = 0; j < n; j++)
        {
            if (min > bt[j] && visit[j] == 0)
            {
                min = bt[j];
                minburst = j;
            }
        }
        visit[minburst] = 1;
        ct[minburst] = ct[preburst] + bt[minburst] - at[preburst];
        preburst = minburst;
    }
    cout << "The completion times of tasks are:";
    for (int k = 0; k < n; k++)
    {
        cout << ct[k] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    for (int c = 0; c < n; c++)
    {
        tatsum += tat[c];
        wtsum += wt[c];
    }
    cout << "The average turn around time is:" << tatsum / n << "\n";
    cout << "THe average weight time is:" << wtsum / n << "\n";
    return 0;
}