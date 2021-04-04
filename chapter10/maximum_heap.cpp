#include <iostream>
static const int MAX = 500000;
using namespace std;

int H;

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

void max_heapify(int array[], int i)
{
  int l = left(i);
  int r = right(i);
  int largest = 0;

  if (l <= H && array[l] > array[i])
  {
    largest = l;
  }
  else
  {
    largest = i;
  }
  if (r <= H && array[r] > array[largest])
  {
    largest = r;
  }

  if (largest != i)
  {
    auto temp = array[i];
    array[i] = array[largest];
    array[largest] = temp;
    max_heapify(array, largest);
  }
}

void build_max_heap(int array[])
{
  for (int i = H / 2; i > 0; --i)
  {
    max_heapify(array, i);
  }
}

int main()
{
  int array[MAX + 1];
  cin >> H;
  for (int i = 1; i <= H; ++i)
  {
    cin >> array[i];
  }

  build_max_heap(array);

  for (int i = 1; i <= H; ++i)
  {
    cout << " " << array[i];
  }
  cout << endl;

  return 0;
}
