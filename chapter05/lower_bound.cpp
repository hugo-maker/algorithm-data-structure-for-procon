#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int array[14] = {1, 1, 2, 2, 2, 4, 5, 5, 6, 8 , 8, 8, 10, 15};
  int * pos = NULL;
  int index = 0;

  pos = lower_bound(array, array + 14, 3);
  index = distance(array, pos);
  cout << "array[" << index << "] = " << *pos << endl;

  pos = lower_bound(array, array + 14, 2);
  index = distance(array, pos);
  cout << "array[" << index << "] = " << *pos << endl;

  return 0;
}
