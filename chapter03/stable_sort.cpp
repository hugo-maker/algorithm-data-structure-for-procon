#include <iostream>
#include <vector>
using namespace std;
static int ARRAY_MAX = 36;

struct card
{
  char suit;
  char value;
};

template <typename T>
void bubble_sort(T & card, const int & n)
{
  bool sorted = false;

  for (int i = 0; !sorted; ++i)
  {
    sorted = true;
    for (int index = n - 1; index >= i + 1; --index)
    {
      if (card[index].value < card[index - 1].value)
      {
        swap(card[index], card[index - 1]);
        sorted = false;
      }
    }
  }
}

template <typename T>
void selection_sort(T & card, const int & n)
{
  for (int outer = 0; outer < n; ++outer)
  {
    int min_index = outer;
    for (int index = outer; index < n; ++index)
    {
      if (card[index].value < card[min_index].value)
      {
        min_index = index;
      }
    }
    swap(card[outer], card[min_index]);
  }
}

template <typename T>
bool is_stable(const T & card1, const T & card2, const int & n)
{
  for (int i = 0; i < n; ++i)
  {
    if (card1[i].suit != card2[i].suit)
    {
      return false;
    }
  }
  return true;
}

template <typename T>
void print_result(const T & card, const int & n)
{
  for (int i = 0; i < n; ++i)
  {
    if (i > 0)
    {
      cout << " ";
    }
    cout << card[i].suit << card[i].value;
  }
  cout << endl;
}

int main()
{
  vector<card> cards_bubble(ARRAY_MAX);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> cards_bubble[i].suit >> cards_bubble[i].value;
  }
  vector<card> cards_selection(cards_bubble);

  bubble_sort(cards_bubble, n);
  print_result(cards_bubble, n);
  cout << "Stable" << endl;

  selection_sort(cards_selection, n);
  print_result(cards_selection, n);
  if (is_stable(cards_selection, cards_bubble, n))
  {
    cout << "Stable" << endl;
  }
  else
  {
    cout << "Not stable" << endl;
  }

  return 0;
}
