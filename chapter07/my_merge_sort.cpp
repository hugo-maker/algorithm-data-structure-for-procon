#include <iostream>
#include <vector>
using namespace std;
static const long long int SENTINEl = 2000000000;

template <typename T>
void merge(T & array, int left, int mid, int right, int & sum)
{
  int n1 = mid - left;
  int n2 = right - mid;

  vector<int> left_array;
  for (int i = 0; i < n1; ++i)
  {
    left_array.push_back(array[left + i]);
  }
  vector<int> right_array;
  for (int i = 0; i < n2; ++i)
  {
    right_array.push_back(array[mid + i]);
  }
  left_array[n1] = SENTINEl;
  right_array[n2] = SENTINEl;

  int i = 0;
  int j = 0;
  for (int k = left; k < right; ++k)
  {
    if (left_array[i] <= right_array[j])
    {
      array[k] = left_array[i];
      ++i;
    }
    else
    {
      array[k] = right_array[j];
      ++j;
    }
    ++sum;
  }
}

template <typename T>
void merge_sort(T & array, int left, int right, int & sum)
{
  if (left + 1 < right)
  {
    int mid = (left + right) / 2;
    merge_sort(array, left, mid, sum);
    merge_sort(array, mid, right, sum);
    merge(array, left, mid, right, sum);
  }
}

int main()
{
  int n = 0;
  int sum = 0;
  cin >> n;

  vector<int> array;
  int temp = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> temp;
    array.push_back(temp);
  }

  merge_sort(array, 0, n, sum);

  for (int i = 0; i < n; ++i)
  {
    if (i > 0)
    {
      cout << ' ';
    }
    cout << array[i];
  }
  cout << endl;
  cout << sum << endl;

  return 0;
}
