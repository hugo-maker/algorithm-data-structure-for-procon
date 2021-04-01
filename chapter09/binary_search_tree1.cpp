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
    if (command == "insert")
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
  }

  return 0;
}
