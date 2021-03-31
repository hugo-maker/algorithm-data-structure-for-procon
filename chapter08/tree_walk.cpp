#include <iostream>
using namespace std;
static const int MAX = 10000;
static const int NIL = -1;

struct node
{
  int id, left, right;
};

struct node tree[MAX];
int n;

void pre_parse(int u)
{
  if (u == NIL)
  {
    return;
  }
  cout << " " << u;
  pre_parse(tree[u].left);
  pre_parse(tree[u].right);
}

void in_parse(int u)
{
  if (u == NIL)
  {
    return;
  }
  in_parse(tree[u].left);
  cout << " " << u;
  in_parse(tree[u].right);
}

void post_parse(int u)
{
  if (u == NIL)
  {
    return;
  }
  post_parse(tree[u].left);
  post_parse(tree[u].right);
  cout << " " << u;
}

int main()
{
  int v, l, r, root;

  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    tree[i].id = NIL;
  }

  for (int i = 0; i < n; ++i)
  {
    cin >> v;
    cin >> l;
    cin >> r;
    tree[v].left = l;
    tree[v].right = r;
    if (l != NIL)
    {
      tree[l].id = v;
    }
    if (r != NIL)
    {
      tree[r].id = v;
    }
  }

  for (int i = 0; i < n; ++i)
  {
    if (tree[i].id == NIL)
    {
      root = i;
    }
  }

  cout << "Preorder" << endl;
  pre_parse(root);
  cout << endl;

  cout << "Inorder" << endl;
  in_parse(root);
  cout << endl;

  cout << "Postorder" << endl;
  post_parse(root);
  cout << endl;

  return 0;
}
