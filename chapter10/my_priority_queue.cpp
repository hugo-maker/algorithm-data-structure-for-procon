#include <queue>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  priority_queue<int> S;
  string command;
  int tmp;

  do
  {
    cin >> command;
    if (command == "end")
    {
      break;
    }
    else if (command == "insert")
    {
      cin >> tmp;
      S.push(tmp);
    }
    else if (command == "extract")
    {
      cout << S.top() << endl;
      S.pop();
    }
  } while (command != "end");

  return 0;
}
