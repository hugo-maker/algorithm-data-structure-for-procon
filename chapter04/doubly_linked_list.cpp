#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
  int n, x;
  char command[20];
  list<int> value;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%s", command);
    if (command[0] == 'i')
    {
      scanf("%d", &x);
      value.push_front(x);
    }
    else if (command[6] == 'L')
    {
      value.pop_back();
    }
    else if (command[6] == 'F')
    {
      value.pop_front();
    }
    else if (command[0] == 'd')
    {
      scanf("%d", &x);
      for (list<int>::iterator iter = value.begin(); iter != value.end(); ++iter)
      {
        if (*iter == x)
        {
          value.erase(iter);
          break;
        }
      }
    }
  }

  int i = 0;
  for (list<int>::iterator iter = value.begin(); iter != value.end(); ++iter)
  {
    if (i++)
    {
      printf(" ");
    }
    printf("%d", *iter);
  }
  printf("\n");

  return 0;
}
