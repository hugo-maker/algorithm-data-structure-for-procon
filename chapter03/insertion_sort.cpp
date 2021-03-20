#include <iostream>
#include <vector>
using namespace std;
static const int ARRAY_MAX = 100;

template <typename T>
void print_elem(const T & array, int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (i > 0)
    {
      cout << " ";
    }
    cout << array[i];
  }
  cout << endl;
}

template <typename T>
void insertion_sort(T & array, int n)
{
  int j, i, value;
  for (i = 1; i < n; ++i)
  {
    value = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > value)
    {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = value;
    print_elem(array, n);
  }
}

int main()
{
  vector<int> array(ARRAY_MAX);
  int n, i, j;

  cin >> n;
  for (i = 0; i < n; ++i)
  {
    cin >> array[i];
  }

  print_elem(array, n);
  insertion_sort(array, n);

  return 0;
}
