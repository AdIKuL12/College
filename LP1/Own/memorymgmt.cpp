#include <bits/stdc++.h>
using namespace std;

void firstFit(vector<int> blockSize, int m, vector<int> processSize, int n)
{
    int allocated[n];
    fill_n(allocated, n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize.at(j) >= processSize.at(i))
            {
                allocated[i] = j;
                blockSize.at(j) -= processSize.at(i);
                break;
            }
        }
    }

    cout << "\nProcessNo.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << processSize.at(i) << "\t\t";
        if (allocated[i] != -1)
            cout << allocated[i] + 1;
        else
            cout << "Not Allocated";
        cout << "\n";
    }
}

void bestFit(vector<int> blockSize, int m, vector<int> processSize, int n)
{
    int allocated[n];
    fill_n(allocated, n, -1);

    for (int i = 0; i < n; i++)
    {
        int idx = -1, size = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            if (blockSize.at(j) >= processSize.at(i) && blockSize.at(j) < size)
            {
                size = blockSize.at(j);
                idx = j;
            }
        }
        if (idx != -1)
        {
            allocated[i] = idx;
            blockSize.at(idx) -= processSize.at(i);
        }
    }

    cout << "\nProcessNo.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << processSize.at(i) << "\t\t";
        if (allocated[i] != -1)
            cout << allocated[i] + 1;
        else
            cout << "Not Allocated";
        cout << "\n";
    }
}

void worstFit(vector<int> blockSize, int m, vector<int> processSize, int n)
{
    int allocated[n];
    fill_n(allocated, n, -1);

    for (int i = 0; i < n; i++)
    {
        int idx = -1, size = 0;
        for (int j = 0; j < m; j++)
        {
            if (blockSize.at(j) >= processSize.at(i) && blockSize.at(j) > size)
            {
                size = blockSize.at(j);
                idx = j;
            }
        }
        if (idx != -1)
        {
            allocated[i] = idx;
            blockSize.at(idx) -= processSize.at(i);
        }
    }

    cout << "\nProcessNo.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << processSize.at(i) << "\t\t";
        if (allocated[i] != -1)
            cout << allocated[i] + 1;
        else
            cout << "Not Allocated";
        cout << "\n";
    }
}

void nextFit(vector<int> blockSize, int m, vector<int> processSize, int n)
{
    int allocated[n];
    fill_n(allocated, n, -1);

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        while (j < m && count < n)
        {
            count++;
            if (processSize[i] <= blockSize[j])
            {
                allocated[i] = j + 1;
                blockSize[j] -= processSize[i];
                break;
            }

            j = (j + 1) % m;
        }
    }

    cout << "\nProcessNo.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << processSize.at(i) << "\t\t";
        if (allocated[i] != -1)
            cout << allocated[i];
        else
            cout << "Not Allocated";
        cout << "\n";
    }
}

int main()
{

    int m, n;

    cout << "Enter number of memory blocks :- ";
    cin >> m;
    cout << "Enter number of processes :- ";
    cin >> n;

    vector<int> blockSize, processSize;

    cout << "--Memory Input--\n";
    for (int i = 0; i < m; i++)
    {
        cout << "Enter size of " << i + 1 << " memory block :- ";
        int x;
        cin >> x;
        blockSize.push_back(x);
    }

    cout << "--Process Input--\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter size of " << i + 1 << " process :- ";
        int x;
        cin >> x;
        processSize.push_back(x);
    }

    int c;
    do
    {
        cout << "Enter fit type:->";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "First Fit";
            firstFit(blockSize, m, processSize, n);
            break;
        case 2:
            cout << "Next Fit";
            nextFit(blockSize, m, processSize, n);
            break;
        case 3:
            cout << "Worst Fit";
            worstFit(blockSize, m, processSize, n);
            break;
        case 4:
            cout << "Best Fit";
            bestFit(blockSize, m, processSize, n);
            break;
        case 5:
            exit(1);
            break;
        }

    } while (c != 5);
    // cout << "\n\t\tFIRST FIT";
    // firstFit(blockSize, m, processSize, n);
    // cout << "\n\t\t BEST FIT";
    // bestFit(blockSize, m, processSize, n);
    // cout << "\n\t\t WORST FIT";
    // worstFit(blockSize, m, processSize, n);
    // cout << "\n";
    // cout << "\n\t\t NEXT FIT";
    // nextFit(blockSize, m, processSize, n);
    // cout << "\n";

    return 0;
}