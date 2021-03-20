#include <iostream>
#include <vector>
using namespace std;
static int ARRAY_MAX = 100;

template <typename T>
void bubble_sort(T & array, int & swap_count, const int & n)
{
  bool sorted = false;

  for (int i = 0; !sorted; ++i)
  {
    sorted = true;
    for (int index = n - 1; index >= i + 1; --index)
    {
      if (array[index] < array[index - 1])
      {
        swap(array[index], array[index - 1]);
        ++swap_count;
        sorted = false;
      }
    }
  }
}

template <typename T>
void print_result(const T & array, const int & swap_count, const int & n)
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
  cout << swap_count << endl;
}

int main()
{
  int swap_count = 0;
  vector<int> array(ARRAY_MAX);
  
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> array[i];
  }

  bubble_sort(array, swap_count, n);
  print_result(array, swap_count, n);

  return 0;
}
