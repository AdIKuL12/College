#include <bits/stdc++.h>
using namespace std;

#define MAX 20
int p[MAX], n, coor;
void ring() {}
void bully() {}
void display()
{
    cout << "----------";
    cout << "Processes: ";
    for (int i = 1; i <= n; i++)
    {
        cout << i << "\t";
    }
    cout << "\n"
         << "Alive: ";
    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << "\t";
    }
    cout << "\n Coordinator -> " << coor << endl;
}

void bully()
{
    int s, c, a, gid, f, sc;
    do
    {
        cout << "-----------------";
        cout << "\n1.crash\n2.activate\n3.display\n4.exit\n";
        cout << "-----------------";
        cout << "Enter choices";
        cin >> s;
        switch (s)
        {
        case 1:
            cout << "Enter a process to crash";
            cin >> c;
            if (p[c])
            {
                p[c] = 0;
            }
            else
            {
                cout << "process " << c << " already dead" << endl;
            }
            do
            {
                cout << "Enter election generation id: ";
                cin >> gid;
                if (gid == coor || p[gid] == 0)
                    cout << "enter valid gid" << endl;
            } while (gid == coor || p[gid] == 0);
            f = 0;
            if (c = coor)
            {
                for (int i = 1 + gid; i <= n; i++)
                {
                    cout << "message is sent from " << gid << " to " << i << endl;
                    if (p[i])
                    {
                        sc = i;
                        cout << "response is sent from " << i << " to " << gid << endl;
                        f = 1;
                    }
                }
                if (f)
                {
                    coor = sc;
                }
                else
                {
                    coor = gid;
                }
            }
            display();
            break;
        }
    }
}
int main()
{
    int c;
    cout << "ENter no of process->";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter state of the process->";
        cin >> p[i];
        if (p[i] == 1)
        {
            coor = i;
        }
    }
    display();
    do
    {
        cout << "--------------\n";
        cout << "1.bully\n2.ring\n3.display\n4.exit\n";
        cout << "-------------\n";
        cout << "enter choice";
        cin >> c;
        switch (c)
        {
        case 1:
            bully();
            break;
        case 2:
            ring();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        }

    } while (c != 3);
    return 0;
}