#include <iostream>
using namespace std;

static const int MAX = 200000;
static const int SENTINEL = 2000000000;
typedef long long llong;

int L[MAX / 2 + 2];
int R[MAX / 2 + 2];

llong merge(int A[], int n, int left, int mid, int right)
{
  int i, j, k;
  llong count = 0;
  int n1 = mid - left;
  int n2 = right - mid;

  for (i = 0; i < n1; ++i)
  {
    L[i] = A[left + i];
  }
  for (i = 0; i < n2; ++i)
  {
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = SENTINEL;

  i = j = 0;
  for (k = left; k < right; ++k)
  {
    if (L[i] <= R[j])
    {
      A[k] = L[i++];
    }
    else
    {
      A[k] = R[j++];
      count += n1 - i;
    }
  }
  return count;
}

llong merge_sort(int A[], int n, int left, int right)
{
  int mid;
  llong v1, v2, v3;
  if (left + 1 < right)
  {
    mid = (left + right) / 2;
    v1 = merge_sort(A, n, left, mid);
    v2 = merge_sort(A, n, mid, right);
    v3 = merge(A, n, left, mid, right);
    return v1 + v2 + v3;
  }
  else
  {
    return 0;
  }
}

int main()
{
  int A[MAX];
  int n;

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> A[i];
  }

  llong ans = merge_sort(A, n, 0, n);
  cout << ans << endl;

  return 0;
}
