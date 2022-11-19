#include <bits/stdc++.h>
using namespace std;

class SJF
{
public:
    float pid, at, bt, ct, st, tat, wt, rt;
};

int main()
{
    int n;
    SJF f[100];
    float avg_tat, avg_wt;
    int total_tat = 0;
    int total_wt = 0;
    int total_rt = 0;
    float thru;
    int iscomp[100];
    memset(iscomp, 0, sizeof(iscomp));
    cout << "No of Processes";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "AT " << i + 1 << ": ";
        cin >> f[i].at;
        cout << "BT " << i + 1 << ": ";
        cin >> f[i].bt;
        f[i].pid = i + 1;
        cout << "\n";
    }
    int current_time = 0;
    int completed = 0;
    int prev = 0;
    while (completed != n)
    {
        int idx = -1;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (f[i].at <= current_time && iscomp[i] == 0)
            {
                if (f[i].bt < mn)
                {
                    idx = i;
                }
                if (f[i].bt == mn)
                {
                    if (f[i].at < f[idx].at)
                    {
                        mn = f[i].bt;
                        idx = i;
                    }
                }
            }
        }
    }
}