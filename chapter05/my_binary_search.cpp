#include <iostream>
#include <vector>
using namespace std;

bool binary_search(const vector<int> & array, const int & n, int key)
{
  int left = 0;
  int right = n;
  int mid = 0;

  while (left < right)
  {
    mid = (left + right) / 2;
    if (key == array[mid])
    {
      return true;
    }

    if (key > array[mid])
    {
      left = mid + 1;
    }
    else if (key < array[mid])
    {
      right = mid;
    }
  }

  return false;
}

int main()
{
  int n = 0;
  int q = 0;
  int key = 0;
  int count = 0;
  int temp = 0;
  vector<int> array;

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
    if (binary_search(array, n, key))
    {
      ++count;
    }
  }
  cout << count << endl;

  return 0;
}
