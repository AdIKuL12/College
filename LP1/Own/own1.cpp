#include <bits/stdc++.h>
using namespace std;

void display(int n, vector<int> ps, vector<int> allocated)
{
    cout << "\nProcessNo.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << ps[i] << "\t\t";
        if (allocated[i] != -1)
            cout << allocated[i] + 1;
        else
            cout << "Not Allocated";
        cout << "\n";
    }
}
void ff(vector<int> bs, int m, vector<int> ps, int n)
{
    vector<int> allocated(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (bs[j] >= ps[i])
            {
                allocated[i] = j;
                bs[j] -= ps[i];
                break;
            }
        }
    }
    display(n, ps, allocated);
}
void bf(vector<int> bs, int m, vector<int> ps, int n)
{
    vector<int> allocated(n, -1);
    for (int i = 0; i < n; i++)
    {
        int idx = -1;
        int size = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            if (bs[j] >= ps[i] && bs[j] < size)
            {
                size = bs[j];
                idx = j;
            }
        }
        if (idx != -1)
        {
            allocated[i] = idx;
            bs[idx] -= ps[i];
        }
    }
    display(n, ps, allocated);
}
void nf(vector<int> bs, int m, vector<int> ps, int n)
{
    vector<int> allocated(n, -1);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        while (j < m && count < n)
        {
            count++;
            if (ps[i] <= bs[j])
            {
                allocated[i] = j + 1;
                bs[j] -= ps[i];
                break;
            }
            j = (j + 1) % m;
        }
    }
    display(n, ps, allocated);
}
void wf(vector<int> bs, int m, vector<int> ps, int n)
{

    vector<int> allocated(n, -1);
    for (int i = 0; i < n; i++)
    {
        int idx = -1, size = 0;
        for (int j = 0; j < m; j++)
        {
            if (bs[j] >= ps[i] && bs[j] > size)
            {
                size = bs[j];
                idx = j;
            }
        }
        if (idx != -1)
        {
            allocated[i] = idx;
            bs[idx] -= ps[i];
        }
    }
    display(n, ps, allocated);
}

int main()
{
    int m, n;
    vector<int> b, p;
    cout << "Enter size of block";
    cin >> m;
    cout << "Enter size of process";
    cin >> n;
    for (int i = 0; i < m; i++)
    {
        int y;
        cout << "Block size " << i + 1 << " is :";
        cin >> y;
        b.push_back(y);
    }
    for (int i = 0; i < n; i++)
    {
        int y;
        cout << "Process size " << i + 1 << " is :";
        cin >> y;
        p.push_back(y);
    }
    int c;
    do
    {
        cin >> c;
        switch (c)
        {
        case 1:
            ff(b, m, p, n);
            break;
        case 2:
            bf(b, m, p, n);
            break;
        case 3:
            nf(b, m, p, n);
            break;
        case 4:
            wf(b, m, p, n);
            break;
        case 5:
            exit(1);
            break;
        }
    } while (c != 5);
    return 0;
}