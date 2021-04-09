#include <iostream>
static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
using namespace std;

int n;
int M[N][N];
int color[N];
int discover[N];
int finish[N];
int tt;

void dfs_visit(int u)
{
  int v;
  color[u] = GRAY;
  discover[u] = ++tt;
  for (v = 0; v < n; ++v)
  {
    if (M[u][v] == 0)
    {
      continue;
    }
    if (color[v] == WHITE)
    {
      dfs_visit(v);
    }
  }
  color[u] = BLACK;
  finish[u] = ++tt;
}

void dfs()
{
  int u;
  for (u = 0; u < n; ++u)
  {
    color[u] = WHITE;
  }
  tt = 0;

  for (u = 0; u < n; ++u)
  {
    if (color[u] == WHITE)
    {
      dfs_visit(u);
    }
  }
  for (u = 0; u < n; ++u)
  {
    cout << u + 1 << " " << discover[u] << " " << finish[u] << endl;
  }
}

int main()
{
  int u, v, k;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      M[i][j] = 0;
    }
  }

  for (int i = 0; i < n; ++i)
  {
    cin >> u;
    cin >> k;
    --u;
    for (int j = 0; j < k; ++j)
    {
      cin >> v;
      --v;
      M[u][v] = 1;
    }
  }

  dfs();

  return 0;
}
