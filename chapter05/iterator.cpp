#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v)
{
  vector<int>::iterator iter;
  for (iter = v.begin(); iter != v.end(); ++iter)
  {
    cout << *iter;
  }
  cout << endl;
}

int main()
{
  int N = 4;
  vector<int> v;

  for (int i = 0; i < N; ++i)
  {
    int x = 0;
    cin >> x;
    v.push_back(x);
  }

  print(v);

  vector<int>::iterator iter = v.begin();
  *iter = 3;
  iter++;
  (*iter)++;

  print(v);

  return 0;
}
