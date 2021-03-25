#include <iostream>
#include <algorithm>
#include <vector>
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

  int q, k, sum = 0;
  cin >> q;
  for (int i = 0; i < q; ++i)
  {
    cin >> k;
    if (*lower_bound(array.begin(), array.end(), k) == k)
    {
      ++sum;
    }
  }

  cout << sum << endl;

  return 0;
}
