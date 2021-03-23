#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
bool search(T & array, int n, int key)
{
  int i = 0;
  array[n] = key;
  while (array[i] != key)
  {
    ++i;
  }
  return (i != n);
}

int main()
{
  int n, q;
  int temp;
  vector<int> array;
  int key;
  int counter;

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> temp;
    array.push_back(temp);
  }

  cin >> q;
  for (int i = 0; i < q; ++i)
  {
    cin >> key;
    if (search(array, n, key))
    {
      ++counter;
    }
  }

  cout << counter << endl;

  return 0;
}
