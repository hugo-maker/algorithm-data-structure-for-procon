#include <iostream>
using namespace std;
static const int MAX = 100000;

int parent(int i)
{
  return i / 2;
}

int left(int i)
{
  return 2 * i;
}

int right(int i)
{
  return 2 * i + 1;
}

int main()
{
  int H;
  int array[MAX + 1];

  cin >> H;
  for (int i = 1; i <= H; ++i)
  {
    cin >> array[i];
  }

  for (int i = 1; i <= H; ++i)
  {
    cout << "node " << i << ": key = " << array[i] << ", ";
    if (parent(i) >= 1)
    {
      cout << "parent key = " << array[parent(i)] << ", ";
    }
    if (left(i) <= H)
    {
      cout << "left key = " << array[left(i)] << ", ";
    }
    if (right(i) <= H)
    {
      cout << "right key = " << array[right(i)] << ", ";
    }
    cout << endl;
  }

  return 0;
}
