#include <iostream>
#include <vector>
using namespace std;
static const int MAX = 10000;

int main()
{
  int n;
  cin >> n;
  vector<int> array(n + 1);
  vector<int> count(MAX + 1);
  for (int i = 0; i < n; ++i)
  {
    cin >> array.at(i + 1);
    ++count.at(array.at(i + 1));
  }

  for (int i = 1; i <= MAX; ++i)
  {
    count.at(i) += count.at(i - 1);
  }

  vector<int> sorted(n + 1);
  for (int i = 1; i <= n; ++i )
  {
    sorted.at(count.at(array.at(i))) = array.at(i);
    --count.at(array.at(i));
  }

  for (int i = 1; i <= n; ++i)
  {
    if (i > 1)
    {
      cout << " ";
    }
    cout << sorted.at(i);
  }
  cout << endl;

  return 0;
}
