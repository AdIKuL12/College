#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void firstFit(vector<int> &blockSize, vector<int> &process, vector<int> &allocated)
{
    // select a process
    for (int i = 0; i < process.size(); i++)
    {
        // find the block for the selected process
        for (int j = 0; j < blockSize.size(); j++)
        {
            if (process[i] <= blockSize[j] && blockSize[j] != 0)
            {
                // if one block is found then terminate and start allocation of next process
                blockSize[j] -= process[i];
                allocated[i] = j;
                break;
            }
        }
    }
}
void bestfit(vector<int> &blockSize, vector<int> &process, vector<int> &allocated)
{
    int idx = -1;
    // select a process
    for (int i = 0; i < process.size(); i++)
    {
        // find the block for selected process
        int diff = 1e9;
        for (int j = 0; j < blockSize.size(); j++)
        {
            // try to minimize the difference
            if (blockSize[j] != 0 && process[i] <= blockSize[j] && blockSize[j] - process[i] <= diff && process[i] != 0)
            {
                idx = j;
                diff = blockSize[j] - process[i];
            }
        }
        // if block found then allocate the memory
        if (idx != -1)
        {
            blockSize[idx] -= process[i];
            allocated[i] = idx;
        }
    }
}
void nextFit(vector<int> &blockSize, vector<int> &process, vector<int> &allocated)
{
    int idx = -1;
    int j = 0;
    int m = blockSize.size();
    // select a process
    for (int i = 0; i < process.size(); i++)
    {
        // loop to find the first block
        while (j < blockSize.size())
        {

            if (blockSize[j] >= process[i])
            {
                allocated[i] = j;
                blockSize[j] -= process[i];
                break;
            }
            // initialize to next block
            j = (j + 1) % m;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of processes: " << endl;
    cin >> n;
    vector<int> process(n);
    cout << "Enter the number of blocks: " << endl;
    cin >> n;
    vector<int> blockSize(n);
    vector<int> allocated(process.size());
    for (int i = 0; i < blockSize.size(); i++)
    {
        cout << "Enter the size of block " << i + 1 << " : ";
        cin >> blockSize[i];
    }
    for (int i = 0; i < process.size(); i++)
    {
        cout << "Enter the size of process " << i + 1 << " : ";
        cin >> process[i];
    }
    cout << "Select the algorithm" << endl;
    cout << "1.Best Fit" << endl;
    cout << "2. First Fit" << endl;
    cout << "3. Next Fit" << endl;
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        bestfit(blockSize, process, allocated);
        break;
    case 2:
        firstFit(blockSize, process, allocated);
        break;
    case 3:
        nextFit(blockSize, process, allocated);
        break;

    default:
        break;
    }
    cout << "Process No."
         << "\t"
         << "Process Size"
         << "\t"
         << "Block Allocated" << endl;
    for (int i = 0; i < allocated.size(); i++)
    {
        cout << "Process " << i + 1 << " : \t\t" << process[i] << "\t\t " << allocated[i] + 1 << endl;
    }

    return 0;
}