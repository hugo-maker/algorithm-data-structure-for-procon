#include <iostream>
#include <vector>
using namespace std;

class disjoint_set
{
public:
  vector<int> rank, p;

  disjoint_set(){}
  disjoint_set(int size)
  {
    rank.resize(size, 0);
    p.resize(size, 0);
    for (int i = 0; i < size; ++i)
    {
      make_set(i);
    }
  }

  void make_set(int x)
  {
    p[x] = x;
    rank[x] = 0;
  }

  bool same(int x, int y)
  {
    return find_set(x) == find_set(y);
  }

  void unite(int x, int y)
  {
    link(find_set(x), find_set(y));
  }

  void link(int x, int y)
  {
    if (rank[x] > rank[y])
    {
      p[y] = x;
    }
    else
    {
      p[x] = y;
      if (rank[x] == rank[y])
      {
        rank[y]++;
      }
    }
  }

  int find_set(int x)
  {
    if (x != p[x])
    {
      p[x] = find_set(p[x]);
    }

    return p[x];
  }
};

int main()
{
  int n, a, b, q;
  int t;

  cin >> n >> q;
  disjoint_set ds = disjoint_set(n);

  for (int i = 0; i < q; ++i)
  {
    cin >> t >> a >> b;
    if (t == 0)
    {
      ds.unite(a, b);
    }
    else if (t == 1)
    {
      if (ds.same(a, b))
      {
        cout << 1 << endl;
      }
      else
      {
        cout << 0 << endl;
      }
    }
  }

  return 0;
}
