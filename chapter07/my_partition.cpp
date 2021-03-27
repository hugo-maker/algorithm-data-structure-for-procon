#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n = 0;
  int temp = 0;
  vector<int> array;
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> temp;
    array.push_back(temp);
  }

  auto pos = stable_partition(array.begin(), array.end(),
      [=] (int x) {return x < array[n - 1]; } );

  auto tmp = *pos;
  *pos = array[n - 1];
  array[n - 1] = tmp;

  for (auto iter = array.begin(); iter != pos; ++iter)
  {
    if (iter != array.begin())
    {
      cout << " ";
    }
    cout << *iter;
  }

  cout << " [" << *pos << "] ";

  for (auto iter = pos + 1; iter != array.end(); ++iter)
  {
    if (iter != pos + 1)
    {
      cout << " ";
    }
    cout << *iter;
  }
  cout << endl;

  return 0;
}
