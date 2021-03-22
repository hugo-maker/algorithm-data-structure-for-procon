#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
  int num = 0;
  int quantum = 0;
  int time = 0;
  string name;

  queue<pair<string, int>> process;

  cin >> num >> quantum;

  for (int i = 0; i < num; ++i)
  {
    cin >> name >> time;
    process.push(make_pair(name, time));
  }

  pair<string, int> work_space;
  int elaps = 0;
  int a = 0;

  while (!process.empty())
  {
    work_space = process.front();
    process.pop();
    a = min(work_space.second, quantum);
    work_space.second -= a;
    elaps += a;
    if (work_space.second > 0)
    {
      process.push(work_space);
    }
    else
    {
      cout << work_space.first << " " << elaps << endl;
    }
  }

  return 0;
}
