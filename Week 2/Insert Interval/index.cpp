#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> ans;
    int newStart = newInterval[0];
    int newEnd = newInterval[1];
    int n = intervals.size();
    bool inserted = false;
    for (int i = 0; i < n; i++)
    {
        if (intervals[i][1] > newStart)
        {
            ans.push_back(intervals[i]);
        }
        else if (intervals[i][0] > newEnd)
        {
            if (!inserted)
            {
                ans.push_back(newInterval);
                inserted = true;
            }
            ans.push_back(intervals[i]);
        }
        else
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }

    if (!inserted)
    {
        ans.push_back(newInterval);
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> op(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        cin >> op[i][0];
        cin >> op[i][1];
    }

    vector<int> newInterval(2);

    for (int i = 0; i < 2; i++)
    {
        cin >> newInterval[i];
    }

    insert(op, newInterval);

    return 0;
}