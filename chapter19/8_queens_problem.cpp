#include <iostream>
#include <cassert>
using namespace std;

static const int N = 8;
static const int FREE = -1;
static const int NOT_FREE = 1;

int row[N];
int col[N];
int dpos[2 * N - 1];
int dneg[2 * N - 1];

bool X[N][N];

void initialize()
{
  for (int i = 0; i < N; ++i)
  {
    row[i] = FREE;
    col[i] = FREE;
  }
  for (int i = 0; i < 2 * N - 1; ++i)
  {
    dpos[i] = FREE;
    dneg[i] = FREE;
  }
}

void print_board()
{
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (X[i][j])
      {
        if (row[i] != j)
        {
          return;
        }
      }
    }
  }
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      cout << ((row[i] == j) ? "Q" : ".");
    }
    cout << endl;
  }
}

void recursive(int i)
{
  if (i == N)
  {
    print_board();
    return;
  }

  for (int j = 0; j < N; ++j)
  {
    if (NOT_FREE == col[j] ||
        NOT_FREE == dpos[i + j] ||
        NOT_FREE == dneg[i - j + N - 1])
    {
      continue;
    }

    row[i] = j;
    col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;
    recursive(i + 1);
    row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
  }
}

int main()
{
  initialize();

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      X[i][j] = false;
    }
  }

  int k;
  cin >> k;
  for (int i = 0; i < k; ++i)
  {
    int r, c;
    cin >> r >> c;
    X[r][c] = true;
  }

  recursive(0);

  return 0;
}
