#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int FCFS(vector<int> requests,
         int head,
         vector<int> &order)
{
    int movement = 0;

    int current = head;

    order.push_back(head);

    for (int i = 0; i < requests.size(); i++)
    {
        movement =
            movement + abs(current - requests[i]);

        current = requests[i];

        order.push_back(current);
    }

    return movement;
}

int SCAN(vector<int> requests,
         int head,
         vector<int> &order)
{
    int movement = 0;

    int current = head;

    vector<int> left;

    vector<int> right;

    order.push_back(head);

    for (int i = 0; i < requests.size(); i++)
    {
        if (requests[i] < head)
        {
            left.push_back(requests[i]);
        }
        else
        {
            right.push_back(requests[i]);
        }
    }

    sort(left.begin(), left.end());

    sort(right.begin(), right.end());

    for (int i = 0; i < right.size(); i++)
    {
        movement =
            movement + abs(current - right[i]);

        current = right[i];

        order.push_back(current);
    }

    movement =
        movement + abs(current - 4999);

    current = 4999;

    order.push_back(current);

    for (int i = left.size() - 1; i >= 0; i--)
    {
        movement =
            movement + abs(current - left[i]);

        current = left[i];

        order.push_back(current);
    }

    return movement;
}

int CSCAN(vector<int> requests,
          int head,
          vector<int> &order)
{
    int movement = 0;

    int current = head;

    vector<int> left;

    vector<int> right;

    order.push_back(head);

    for (int i = 0; i < requests.size(); i++)
    {
        if (requests[i] < head)
        {
            left.push_back(requests[i]);
        }
        else
        {
            right.push_back(requests[i]);
        }
    }

    sort(left.begin(), left.end());

    sort(right.begin(), right.end());

    for (int i = 0; i < right.size(); i++)
    {
        movement =
            movement + abs(current - right[i]);

        current = right[i];

        order.push_back(current);
    }

    movement =
        movement + abs(current - 4999);

    current = 4999;

    order.push_back(current);

    movement =
        movement + 4999;

    current = 0;

    order.push_back(current);

    for (int i = 0; i < left.size(); i++)
    {
        movement =
            movement + abs(current - left[i]);

        current = left[i];

        order.push_back(current);
    }

    return movement;
}

void saveOrder(ofstream &file,
               string algorithm,
               vector<int> order)
{
    for (int i = 0; i < order.size(); i++)
    {
        file << algorithm
             << ","
             << i
             << ","
             << order[i]
             << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Use: ./program initial_head_position"
             << endl;
    }
    else
    {
        int head = atoi(argv[1]);

        vector<int> requests;

        srand(time(0));

        for (int i = 0; i < 1000; i++)
        {
            requests.push_back(rand() % 5000);
        }

        vector<int> fcfsOrder;

        vector<int> scanOrder;

        vector<int> cscanOrder;

        int fcfs =
            FCFS(requests,
                 head,
                 fcfsOrder);

        int scan =
            SCAN(requests,
                 head,
                 scanOrder);

        int cscan =
            CSCAN(requests,
                  head,
                  cscanOrder);

        cout << "Initial head position: "
             << head << endl;

        cout << "FCFS total movement: "
             << fcfs << endl;

        cout << "SCAN total movement: "
             << scan << endl;

        cout << "C-SCAN total movement: "
             << cscan << endl;

        ofstream file("results.csv");

        file << "Algorithm,Step,Cylinder"
             << endl;

        saveOrder(file,
                  "FCFS",
                  fcfsOrder);

        saveOrder(file,
                  "SCAN",
                  scanOrder);

        saveOrder(file,
                  "CSCAN",
                  cscanOrder);

        file.close();

        cout << endl;

        cout << "Results exported to results.csv"
             << endl;
    }

    return 0;
}