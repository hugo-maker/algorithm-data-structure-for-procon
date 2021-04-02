#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct node
{
  int key;
  node * right;
  node * left;
  node * parent;
};

node * root;
node * NIL;

node * tree_minimum(node * x)
{
  while (x->left != NIL)
  {
    x = x->left;
  }

  return x;
}

node * find(node * u, int k)
{
  while (u != NIL && k != u->key)
  {
    if (k < u->key)
    {
      u = u->left;
    }
    else
    {
      u = u->right;
    }
  }

  return u;
}

node * tree_successor(node * x)
{
  if (x->right != NIL)
  {
    return tree_minimum(x->right);
  }
  node * y = x->parent;
  while (y != NIL && x == y->right)
  {
    x = y;
    y = y->parent;
  }

  return y;
}

void tree_delete(node * z)
{
  node * y;
  node * x;

  if (z->left == NIL || z->right == NIL)
  {
    y = z;
  }
  else
  {
    y = tree_successor(z);
  }

  if (y->left != NIL)
  {
    x = y->left;
  }
  else
  {
    x = y->right;
  }

  if (x != NIL)
  {
    x->parent = y->parent;
  }

  if (y->parent == NIL)
  {
    root = x;
  }
  else
  {
    if (y == y->parent->left)
    {
      y->parent->left = x;
    }
    else
    {
      y->parent->right = x;
    }
  }

  if (y != z)
  {
    z->key = y->key;
  }

  free(y);
}

void insert(int k)
{
  node * y = NIL;
  node * x = root;
  node * z;

  z = (node *)malloc(sizeof(node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL)
  {
    y = x;
    if (z->key < x->key)
    {
      x = x->left;
    }
    else
    {
      x = x->right;
    }
  }

  z->parent = y;
  if (y == NIL)
  {
    root = z;
  }
  else
  {
    if (z->key < y->key)
    {
      y->left = z;
    }
    else
    {
      y->right = z;
    }
  }
}

void inorder(node * u)
{
  if (u == NIL)
  {
    return;
  }

  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}

void preorder(node * u)
{
  if (u == NIL)
  {
    return;
  }

  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}

int main()
{
  int n, x;
  string command;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    cin >> command;
    if (command[0] == 'f')
    {
      scanf("%d", &x);
      node * t = find(root, x);
      if (t != NIL)
      {
        printf("yes\n");
      }
      else
      {
        printf("no\n");
      }
    }
    else if (command == "insert")
    {
      scanf("%d", &x);
      insert(x);
    }
    else if (command == "print")
    {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
    else if (command == "delete")
    {
      scanf("%d", &x);
      tree_delete(find(root, x));
    }
  }

  return 0;
}
