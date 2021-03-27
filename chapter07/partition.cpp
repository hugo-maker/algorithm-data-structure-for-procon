#include <iostream>
static const int MAX = 100000;

int array[MAX];
int n;

int partition(int p, int r)
{
  int x, i, j, temp;
  x = array[r];
  i = p - 1;
  for (j = p; j < r; ++j)
  {
    if (array[j] <= x)
    {
      ++i;
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  temp = array[i + 1];
  array[i + 1] = array[r];
  array[r] = temp;

  return i + 1;
}

int main()
{
  using namespace std;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> array[i];
  }

  int q = partition(0, n - 1);

  for (int i = 0; i < n; ++i)
  {
    if (i)
    {
      cout << " ";
    }
    if (i == q)
    {
      cout << "[";
    }
    cout << array[i];
    if (i == q)
    {
      cout << "]";
    }
  }
  cout << endl;

  return 0;
}
