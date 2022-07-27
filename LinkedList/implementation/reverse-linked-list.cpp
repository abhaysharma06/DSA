#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head = NULL;

void createList()
{
  struct Node *new_node, *current_node;
  int n;
  cout << "Enter the node";
  cin >> n;
  while (n)
  {

    new_node = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter the data of Node"
         << " ";
    cin >> new_node->data;
    new_node->next = NULL;

    if (head == NULL)
    {
      head = new_node;
    }
    else
    {
      current_node->next = new_node;
    }
    current_node = new_node;
    --n;
  }
}

void display()
{
  struct Node *start = head;
  cout << "Display the linked list"
       << " ";
  while (start)
  {
    cout << start->data << " ";
    start = start->next;
  }
}

void reverseDisplay(struct Node *start)
{
  if (start == NULL)
    return;
  cout << "Display the reverse linked list"
       << " ";
  reverseDisplay(start->next);
  cout << start->data << " ";
}

int main()
{
  createList();
  display();
  reverseDisplay(head);
  return 0;
}