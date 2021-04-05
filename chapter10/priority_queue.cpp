#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
static const int MAX = 2000000;
static const int INFTY = 1 << 30;

int H;
int array[MAX + 1];

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

int extract()
{
  int max_value;
  if (H < 1)
  {
    return -INFTY;
  }
  max_value = array[1];
  array[1] = array[H--];
  max_heapify(array, 1);
  return max_value;
}

void increase_key(int i, int key)
{
  if (key < array[i])
  {
    return;
  }
  array[i] = key;
  while (i > 1 && array[i / 2] < array[i])
  {
    swap(array[i], array[i / 2]);
    i = i / 2;
  }
}

void insert(int key)
{
  H++;
  array[H] = -INFTY;
  increase_key(H, key);
}

int main()
{
  int key;
  char command[10];

  while (true)
  {
    scanf("%s", command);
    if (command[0] == 'e' && command[1] == 'n')
    {
      break;
    }
    if (command[0] == 'i')
    {
      scanf("%d", &key);
      insert(key);
    }
    else
    {
      printf("%d\n", extract());
    }
  }

  return 0;
}
