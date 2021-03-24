#include <iostream>
using namespace std;

#define h1(key) ((key) % (M))
#define h2(key) (1 + ((key) % ((M) - 1)))

static const int M = 1046527;
string str[M];

int get_code(char c)
{
  switch (c)
  {
    case 'A':
    {
      return 1;
      break;
    }
    case 'C':
    {
      return 2;
      break;
    }
    case 'G':
    {
      return 3;
      break;
    }
  }
  return 4;
}

long long get_key(string input)
{
  long long sum = 0;
  long long p = 1;
  for (size_t i = 0; i < input.size(); ++i)
  {
    sum += (get_code(input[i]) * p);
    p *= 5;
  }
  return sum;
}

long long hash_f(long long key, int i)
{
  return (h1(key) + i * h2(key)) % M;
}

bool find(string input)
{
  long long key = get_key(input);

  for (int i = 1;;++i)
  {
    long long h = hash_f(key, i);
    if (str[h] == input)
    {
      return true;
    }
    else if (str[h].size() == 0)
    {
      return false;
    }
  }
}

void insert(string input)
{
  long long key = get_key(input);
  for (int i = 1;;++i)
  {
    long long h = hash_f(key, i);
    if (str[h].size() == 0)
    {
      str[h] = input;
      break;
    }
  }
}

int main()
{
  int n;
  string command, input;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> command >> input;
    if (command == "insert")
    {
      insert(input);
    }
    else
    {
      if (find(input))
      {
        cout << "yes" << endl;
      }
      else
      {
        cout << "no" << endl;
      }
    }
  }

  return 0;
}
