#include <cstdio>
#include <cstdlib>
#include <cstring>

struct node
{
  int key;
  node * prev;
  node * next;
};

node * nil;

void init()
{
  nil = (node *)malloc(sizeof(node));
  nil->next = nil;
  nil->prev = nil;
}

void insert(int key)
{
  node * new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  new_node->next = nil->next;
  nil->next->prev = new_node;
  nil->next = new_node;
  new_node->prev = nil;
}

node * list_search(int key)
{
  node * cur = nil->next;
  while (cur != nil && cur->key != key)
  {
    cur = cur->next;
  }
  return cur;
}

void delete_node(node * target)
{
  if (target == nil)
  {
    return;
  }

  target->prev->next = target->next;
  target->next->prev= target->prev;
  free(target);
}

void delete_first()
{
  delete_node(nil->next);
}

void delete_last()
{
  delete_node(nil->prev);
}

void delete_key(int key)
{
  delete_node(list_search(key));
}

void print_list()
{
  node * cur = nil->next;
  int isf = 0;
  while (1)
  {
    if (cur == nil)
    {
      break;
    }
    if (isf++ > 0)
    {
      printf(" ");
    }
    printf("%d", cur->key);
    cur = cur->next;
  }
  printf("\n");
}

int main()
{
  int key = 0;
  int n = 0;
  int i = 0;
  int size = 0;
  char command[20];
  int np = 0;
  int nd = 0;

  scanf("%d", &n);
  init();

  for (i = 0; i < n; ++i)
  {
    scanf("%s%d", command, &key);
    if (command[0] == 'i')
    {
      insert(key);
      ++np;
      ++size;
    }
    else if (command[0] == 'd')
    {
      if (strlen(command) > 6)
      {
        if (command[6] == 'F')
        {
          delete_first();
        }
        else if (command[6] == 'L')
        {
          delete_last();
        }
      }
      else
      {
        delete_key(key);
        ++nd;
      }
      --size;
    }
  }

  print_list();

  return 0;
}
