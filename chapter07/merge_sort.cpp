#include <iostream>
using namespace std;
static const long long int SENTINEL = 2000000000;
static const int MAX = 500000;

int left_array[MAX / 2 + 2];
int right_array[MAX / 2 + 2];
int sum;

void merge(int array[], int n, int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;

  for (int i = 0; i < n1; ++i)
  {
    left_array[i] = array[left + i];
  }
  for (int i = 0; i < n2; ++i)
  {
    right_array[i] = array[mid + i];
  }
  left_array[n1] = SENTINEL;
  right_array[n2] = SENTINEL;

  int i = 0;
  int j = 0;
  for (int k = left; k < right; ++k)
  {
    ++sum;
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
  }
}

void merge_sort(int array[], int n, int left, int right)
{
  if (left + 1 < right)
  {
    int mid = (left + right) / 2;
    merge_sort(array, n, left, mid);
    merge_sort(array, n, mid, right);
    merge(array, n, left, mid, right);
  }
}

int main()
{
  int array[MAX];
  int n = 0;

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> array[i];
  }

  merge_sort(array, n, 0, n);

  for (int i = 0; i < n; ++i)
  {
    if (i)
    {
      cout << " ";
    }
    cout << array[i];
  }
  cout << endl;

  cout << sum << endl;

  return 0;
}
