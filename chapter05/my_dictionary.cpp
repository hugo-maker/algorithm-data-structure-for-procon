#include <map>
#include <iostream>
#include <string>
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

int main()
{
  int n = 0;
  string command, input;
  map<long long, string> dictionary;

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> command >> input;
    long long key = get_key(input);
    if (command == "insert")
    {
      dictionary.insert(make_pair(key, input));
    }
    else
    {
      auto found = dictionary.find(key);
      if (found != dictionary.end())
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
