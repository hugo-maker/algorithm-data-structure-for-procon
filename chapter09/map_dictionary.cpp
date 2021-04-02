#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
  int n;
  char str[13];
  char command[10];
  map<string, bool> T;

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> command;
    cin >> str;
    if (command[0] == 'i')
    {
      T[string(str)] = true;
    }
    else
    {
      if (T[string(str)])
      {
        cout << "yes" << endl;
      }
      else
      {
        cout << "no" << endl;
      }
    }
  }

  return 0;
}
