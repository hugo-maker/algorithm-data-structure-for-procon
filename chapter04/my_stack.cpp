#include <stack>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  stack<int> int_in_stack;
  char symbol[256];

  int operand1, operand2;

  while (cin >> symbol)
  {
    if (symbol[0] == '+')
    {
      operand1 = int_in_stack.top();
      int_in_stack.pop(); 
      operand2 = int_in_stack.top();
      int_in_stack.pop(); 

      int_in_stack.push(operand1 + operand2);
    }
    else if (symbol[0] == '-')
    {
      operand2 = int_in_stack.top();
      int_in_stack.pop(); 
      operand1 = int_in_stack.top();
      int_in_stack.pop(); 

      int_in_stack.push(operand1 - operand2);
    }
    else if (symbol[0] == '*')
    {
      operand1 = int_in_stack.top();
      int_in_stack.pop(); 
      operand2 = int_in_stack.top();
      int_in_stack.pop(); 

      int_in_stack.push(operand1 * operand2);
    }
    else
    {
      int_in_stack.push(atoi(symbol));
    }
  }

  cout << int_in_stack.top() << endl;

  return 0;
}
