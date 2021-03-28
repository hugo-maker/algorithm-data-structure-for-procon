#include <iostream>
#include <vector>
using namespace std;
static const int MAX = 10001;

int main()
{
  int n;
  cin >> n;
  vector<int> array(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> array.at(i);
  }

  vector<int> count(MAX);
  for (int i = 0; i < n; ++i)
  {
    ++count.at(array.at(i));
  }

  vector<int> sum(MAX);
  sum.at(0) = count.at(0);
  for (int i = 1; i < MAX; ++i)
  {
    sum.at(i) = sum.at(i - 1) + count.at(i);
  }

  vector<int> sorted(n);
  for (int i = n - 1; i >= 0; --i)
  {
    --sum.at(array.at(i));
    sorted.at(sum.at(array.at(i))) = array.at(i);
  }

  for (int i = 0; i < n; ++i)
  {
    if (i)
    {
      cout << " ";
    }
    cout << sorted.at(i);
  }
  cout << endl;

  return 0;
}
