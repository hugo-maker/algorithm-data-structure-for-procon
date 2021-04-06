#include <iostream>
using namespace std;

int dynamic_programming[50];

int fibonacci(int n)
{
  if (n == 0 || n == 1)
  {
    return dynamic_programming[n] = 1;
  }
  if (dynamic_programming[n] != -1)
  {
    return dynamic_programming[n];
  }

  return dynamic_programming[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
  int n;
  for (int i = 0; i < 50; ++i)
  {
    dynamic_programming[i] = -1;
  }

  cin >> n;
  cout << fibonacci(n) << endl;

  return 0;
}
