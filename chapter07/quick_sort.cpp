#include <iostream>
#include <cstdio>
static const int MAX = 100000;
static const long long int SENTINEL = 2000000000;

struct card
{
  char suit;
  int value;
};

struct card left_array[MAX / 2 + 2];
struct card right_array[MAX / 2 + 2];

template <typename T>
void merge(T & array, int n, int left, int mid, int right)
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
  left_array[n1].value = SENTINEL;
  right_array[n2].value = SENTINEL;

  int i = 0;
  int j = 0;
  for (int k = left; k < right; ++k)
  {
    if (left_array[i].value <= right_array[j].value)
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

template <typename T>
void merge_sort(T & array, int n, int left, int right)
{
  if (left + 1 < right)
  {
    int mid = (left + right) / 2;
    merge_sort(array, n, left, mid);
    merge_sort(array, n, mid, right);
    merge(array, n, left, mid, right);
  }
}

template <typename T>
int partition(T & array, int n, int p, int r)
{
  int i, j;
  struct card temp, x;
  x = array[r];
  i = p - 1;
  for (j = p; j < r; ++j)
  {
    if (array[j].value <= x.value)
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

template <typename T>
void quick_sort(T & array, int n, int p, int r)
{
  if (p < r)
  {
    int q = partition(array, n, p, r);
    quick_sort(array, n, p, q - 1);
    quick_sort(array, n, q + 1, r);
  }
}

int main()
{
  using namespace std;
  int n, v;
  struct card array_q[MAX], array_m[MAX];
  char symbol[10];
  bool stable = true;

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    scanf("%s %d", symbol, &v);
    array_q[i].suit = array_m[i].suit = symbol[0];
    array_q[i].value = array_m[i].value = v;
  }

  merge_sort(array_m, n, 0, n);
  quick_sort(array_q, n, 0, n - 1);

  for (int i = 0; i < n; ++i)
  {
    if (array_m[i].suit != array_q[i].suit)
    {
      stable = false;
    }
  }

  if (stable)
  {
    cout << "Stable" << endl;
  }
  else
  {
    cout << "Not stable" << endl;
  }

  for (int i = 0; i < n; ++i)
  {
    cout << array_q[i].suit << " " << array_q[i].value << endl;
  }

  return 0;
}
