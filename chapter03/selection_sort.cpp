#include <iostream>
#include <vector>
using namespace std;
static int ARRAY_MAX = 100;

template <typename T>
void selection_sort(T & array, int & swap_count, const int & n)
{
  for (int outer = 0; outer < n; ++outer)
  {
    int min_index = outer;
    for (int index = outer; index < n; ++index)
    {
      if (array[index] < array[min_index])
      {
        min_index = index;
      }
    }
    if (outer != min_index)
    {
      swap(array[outer], array[min_index]);
      ++swap_count;
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

  selection_sort(array, swap_count, n);
  print_result(array, swap_count, n);

  return 0;
}
