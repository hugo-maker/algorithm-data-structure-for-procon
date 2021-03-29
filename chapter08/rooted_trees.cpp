#include <iostream>
using namespace std;
static const int MAX = 100005;
static const int NIL = -1;

struct node
{
  int parent;
  int left;
  int right;
};

node tree[MAX];
int n;
int depth[MAX];

void print(int u)
{
  cout << "node " << u << ": ";
  cout << "parent = " << tree[u].parent << ", ";
  cout << "depth = " << depth[u] << ", ";

  if (tree[u].parent == NIL)
  {
    cout << "root, ";
  }
  else if (tree[u].left == NIL)
  {
    cout << "leaf, ";
  }
  else
  {
    cout << "internal node, ";
  }

  cout << "[";

  for (int i = 0, child = tree[u].left; child != NIL; ++i, child = tree[child].right)
  {
    if (i)
    {
      cout << ", ";
    }
    cout << child;
  }
  cout << "]" << endl;
}

void recursive(int u, int parent)
{
  depth[u] = parent;
  if (tree[u].right != NIL)
  {
    recursive(tree[u].right, parent);
  }
  if (tree[u].left != NIL)
  {
    recursive(tree[u].left, parent + 1);
  }
}

int main()
{
  int left, right;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    tree[i].parent = tree[i].left = tree[i].right = NIL;
  }

  int id, k, child;
  for (int i = 0; i < n; ++i)
  {
    cin >> id >> k;
    for (int j = 0; j < k; ++j)
    {
      cin >> child;
      if (j == 0)
      {
        tree[id].left = child;
      }
      else
      {
        tree[left].right = child;
      }
      left = child;
      tree[child].parent = id;
    }
  }
  for (int i = 0; i < n; ++i)
  {
    if (tree[i].parent == NIL)
    {
      right = i;
    }
  }

  recursive(right, 0);

  for (int i = 0; i < n; ++i)
  {
    print(i);
  }

  return 0;
}
