#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int MAX = 10000;
static const int INFTY = (1<<29);

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

class edge
{
public:
  int source, target, cost;
  edge(int source = 0, int target = 0, int cost = 0)
    : source(source), target(target), cost(cost) {}

  bool operator < (const edge & e) const
  {
    return cost < e.cost;
  }
};

int kruskal(int N, vector<edge> edges)
{
  int total_cost = 0;
  sort(edges.begin(), edges.end());

  disjoint_set dset = disjoint_set(N + 1);

  for (int i = 0; i < N; ++i)
  {
    dset.make_set(i);
  }

  int source, target;
  for (int i = 0; i < edges.size(); ++i)
  {
    edge e = edges[i];
    if (!dset.same(e.source, e.target))
    {
      total_cost += e.cost;
      dset.unite(e.source, e.target);
    }
  }
  return total_cost;
}

int main()
{
  int N, M, cost;
  int source, target;

  cin >> N >> M;

  vector<edge> edges;
  for (int i = 0; i < M; ++i)
  {
    cin >> source >> target >> cost;
    edges.push_back(edge(source, target, cost));
  }

  cout << kruskal(N, edges) << endl;

  return 0;
}
