#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

struct Node *head = NULL;

void createLinkedList()
{
  int n;
  struct Node *newNode, *current;
  cout << "Enter the number of node";
  cin >> n;

  while (n)
  {

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
      cout << "Memory Error" << endl;
      return;
    }

    cout << "Enter the data part";
    cin >> newNode->data;
    newNode->next = NULL;

    if (head == NULL)
    {
      head = newNode;
    }
    else
    {
      current->next = newNode;
    }
    current = newNode;
    --n;
  }

  // newNode->data = data;
  // newNode->next = head;
  // head = newNode;
}

void display()
{
  struct Node *ptr;
  ptr = head;
  while (ptr != NULL)
  {
    cout << ptr->data << endl;
    ptr = ptr->next;
  }
}

int main()
{
  createLinkedList();
  display();
  return 0;
}