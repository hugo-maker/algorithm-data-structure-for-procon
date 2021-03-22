#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct process
{
  char name[100];
  int time;
};

int main()
{
  int elapsed_time = 0;
  int counter = 0;
  int quantum = 0;
  int process_num = 0;
  queue<process> processes;
  process temp;

  cin >> process_num >> quantum;

  for (int i = 1; i <= process_num; ++i)
  {
    cin >> temp.name;
    cin >> temp.time;
    processes.push(temp);
  }

  while (!processes.empty())
  {
    temp = processes.front();
    processes.pop();
    counter = min(quantum, temp.time);
    temp.time -= counter;
    elapsed_time += counter;
    if (temp.time > 0)
    {
      processes.push(temp);
    }
    else
    {
      cout << temp.name << " " << elapsed_time << endl;
    }
  }

  return 0;
}
