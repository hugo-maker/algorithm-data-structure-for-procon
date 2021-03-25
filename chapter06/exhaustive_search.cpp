#include <iostream>
#include <vector>
using namespace std;

template <typename T>
bool solve(const T & array, const int & n, int i, int m)
{
  if (m == 0)
  {
    return true;
  }
  if (i >= n)
  {
    return false;
  }
  int result = solve(array, n, i + 1, m) || solve(array, n, i + 1, m - array[i]);
  return result;
}

int main()
{
  int n, temp, q, m; 
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
    cin >> m;
    if (solve(array, n, 0, m))
    {
      cout << "yes" << endl;
    }
    else
    {
      cout << "no" << endl;
    }
  }

  return 0;
}
