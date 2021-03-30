#include <cstdio>
static const int MAX = 10000;
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
int height[MAX];

void set_depth(int u, int d)
{
  if (u == NIL)
  {
    return;
  }
  depth[u] = d;
  set_depth(tree[u].left, d + 1);
  set_depth(tree[u].right, d + 1);
}

int set_height(int u)
{
  int h1 = 0;
  int h2 = 0;

  if (tree[u].left != NIL)
  {
    h1 = set_height(tree[u].left) + 1;
  }
  if (tree[u].right != NIL)
  {
    h2 = set_height(tree[u].right) + 1;
  }

  return height[u] = (h1 > h2 ? h1 : h2);
}

int get_sibling(int u)
{
  if (tree[u].parent == NIL)
  {
    return NIL;
  }
  if (tree[tree[u].parent].left != u && tree[tree[u].parent].left != NIL)
  {
    return tree[tree[u].parent].left;
  }
  if (tree[tree[u].parent].right != u && tree[tree[u].parent].right != NIL)
  {
    return tree[tree[u].parent].right;
  }

  return NIL;
}

void print(int u)
{
  printf("node %d: ", u);
  printf("parent = %d, ", tree[u].parent);
  printf("sibling = %d, ", get_sibling(u));
  int degree = 0;
  if (tree[u].left != NIL)
  {
    ++degree;
  }
  if (tree[u].right != NIL)
  {
    ++degree;
  }
  printf("degree = %d, ", degree);
  printf("depth = %d, ", depth[u]);
  printf("height = %d, ", height[u]);

  if (tree[u].parent == NIL)
  {
    printf("root\n");
  }
  else if (tree[u].left == NIL && tree[u].right == NIL)
  {
    printf("leaf\n");
  }
  else
  {
    printf("internal node\n");
  }
}

int main()
{
  int value = 0;
  int left = 0;
  int right = 0;
  int root = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    tree[i].parent = NIL;
  }

  for (int i = 0; i < n; ++i)
  {
    scanf("%d %d %d", &value, &left, &right);
    tree[value].left = left;
    tree[value].right = right;
    if (left != NIL)
    {
      tree[left].parent = value;
    }
    if (right != NIL)
    {
      tree[right].parent = value;
    }
  }

  for (int i = 0; i < n; ++i)
  {
    if (tree[i].parent == NIL)
    {
      root = i;
    }
  }

  set_depth(root, 0);
  set_height(root);

  for (int i = 0; i < n; ++i)
  {
    print(i);
  }

  return 0;
}
