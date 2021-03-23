#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, q;
  int temp;
  vector<int> S;
  vector<int> T;

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> temp;
    S.push_back(temp);
  }

  cin >> q;
  for (int i = 0; i < q; ++i)
  {
    cin >> temp;
    T.push_back(temp);
  }

  int count = 0;
  for (int i = 0; i < q; ++i)
  {
    auto result = find(S.begin(), S.end(), T[i]);
    if (result != S.end())
    {
      ++count;
    }
  }

  cout << count << endl;

  return 0;
}
