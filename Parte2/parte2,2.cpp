#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int FCFS(vector<int> requests, int head)
{
    int movement = 0;
    int current = head;
    for (int i = 0; i < requests.size(); i++)
    {
        movement = movement + abs(current - requests[i]);
        current = requests[i];
    }
    return movement;
}

int SCAN(vector<int> requests, int head)
{
    int movement = 0;
    int current = head;
    vector<int> left;
    vector<int> right;
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
        movement = movement + abs(current - right[i]);
        current = right[i];
    }
    movement = movement + abs(current - 4999);
    current = 4999;
    for (int i = left.size() - 1; i >= 0; i--)
    {
        movement = movement + abs(current - left[i]);
        current = left[i];
    }
    return movement;
}

int CSCAN(vector<int> requests, int head)
{
    int movement = 0;
    int current = head;
    vector<int> left;
    vector<int> right;
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
        movement = movement + abs(current - right[i]);
        current = right[i];
    }
    movement = movement + abs(current - 4999);
    current = 4999;
    movement = movement + 4999;
    current = 0;
    for (int i = 0; i < left.size(); i++)
    {
        movement = movement + abs(current - left[i]);
        current = left[i];
    }
    return movement;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Use: ./program initial_head_position" << endl;
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
        cout << "Initial head position: " << head << endl;
        cout << "FCFS total movement: "
             << FCFS(requests, head) << endl;
        cout << "SCAN total movement: "
             << SCAN(requests, head) << endl;
        cout << "C-SCAN total movement: "
             << CSCAN(requests, head) << endl;
    }
    return 0;
}