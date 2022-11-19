// #include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;

class FCFS
{
public:
    int pid, at, bt, ct, st, tat, wt, rt;
};

bool compat(FCFS a1, FCFS a2)
{
    return a1.at < a2.at;
}
bool compid(FCFS a1, FCFS a2)
{
    return a1.pid < a2.pid;
}

int main()
{
    int n;
    FCFS f[100];
    float avg_tat, avg_wt, avg_rt;
    float total_tat = 0;
    float total_wt = 0;
    float total_rt = 0;
    cout << "No of Processes->";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter AT " << i + 1 << ": ";
        cin >> f[i].at;
        cout << "Enter BT " << i + 1 << ": ";
        cin >> f[i].bt;
        f[i].pid = i + 1;
        cout << "/n";
    }
    sort(f, f + n, compat);
    for (int i = 0; i < n; i++)
    {
        f[i].st = (i == 0) ? f[i].at : max(f[i - 1].ct, f[i].at);
        f[i].ct = f[i].st + f[i].bt;
        f[i].tat = f[i].ct - f[i].at;
        f[i].wt = f[i].tat - f[i].bt;
        f[i].rt = f[i].st - f[i].at;
        total_tat += f[i].tat;
        total_wt += f[i].wt;
        total_rt += f[i].rt;
    }
    avg_tat = total_tat / n;
    avg_wt = total_wt / n;

    sort(f, f + n, compid);
    cout << endl;
    cout << "#P\t"
         << "AT\t"
         << "BT\t"
         << "ST\t"
         << "CT\t"
         << "TAT\t"
         << "WT\t"
         << "RT\t"
         << "\n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << f[i].pid << "\t" << f[i].at << "\t" << f[i].bt << "\t" << f[i].st << "\t" << f[i].ct << "\t" << f[i].tat << "\t" << f[i].wt << "\t" << f[i].rt << "\t\n";
    }
    cout << "Avg TAT" << avg_tat << endl;
    cout << "Avg Wt" << avg_wt << endl;
}
