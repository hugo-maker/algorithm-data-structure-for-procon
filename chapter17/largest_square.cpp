#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 1400;

int dp[MAX][MAX];
int G[MAX][MAX];

int get_largest_square(int H, int W)
{
  int max_width = 0;
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      dp[i][j] = (G[i][j] + 1) % 2;
      max_width |= dp[i][j];
    }
  }

  for (int i = 1; i < H; ++i)
  {
    for (int j = 1; j < W; ++j)
    {
      if (G[i][j])
      {
        dp[i][j] = 0;
      }
      else
      {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        max_width = max(max_width, dp[i][j]);
      }
    }
  }

  return max_width * max_width;
}

int main()
{
  int H, W;
  cin >> H >> W;

  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      cin >> G[i][j];
    }
  }

  cout << get_largest_square(H, W) << endl;

  return 0;
}
