#include <stack>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
  stack<int> int_in_stack;
  int a, b;
  string symbol;

  while (cin >> symbol)
  {
    if (symbol[0] == '+')
    {
      a = int_in_stack.top();
      int_in_stack.pop(); 
      b = int_in_stack.top();
      int_in_stack.pop(); 

      int_in_stack.push(a + b);
    }
    else if (symbol[0] == '-')
    {
      b = int_in_stack.top();
      int_in_stack.pop(); 
      a = int_in_stack.top();
      int_in_stack.pop(); 

      int_in_stack.push(a - b);
    }
    else if (symbol[0] == '*')
    {
      a = int_in_stack.top();
      int_in_stack.pop(); 
      b = int_in_stack.top();
      int_in_stack.pop(); 

      int_in_stack.push(a * b);
    }
    else
    {
      int_in_stack.push(atoi(symbol.c_str()));
    }
  }

  cout << int_in_stack.top() << endl;

  return 0;
}
