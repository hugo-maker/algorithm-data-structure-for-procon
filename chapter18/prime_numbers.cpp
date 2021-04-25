#include <iostream>
using namespace std;

bool is_prime(int x)
{
  if (x < 2)
  {
    return false;
  }
  else if (x == 2)
  {
    return true;
  }

  if (x % 2 == 0)
  {
    return false;
  }

  for (int i = 3; i * i <= x; i += 2)
  {
    if (x % i == 0)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  int n, x;
  int count = 0;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> x;
    if (is_prime(x))
    {
      ++count;
    }
  }
  cout << count << endl;

  return 0;
}
