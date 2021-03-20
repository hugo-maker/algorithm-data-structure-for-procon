#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 200000;

int main()
{
  int R[MAX], n;

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> R[i];
  }

  int max_diff = R[1] - R[0];
  int min_value = R[0];

  for (int i = 1; i < n; ++i)
  {
    max_diff = max(max_diff, R[i] - min_value);
    min_value = min(min_value, R[i]);
  }

  cout << max_diff << endl;

  return 0;
}
