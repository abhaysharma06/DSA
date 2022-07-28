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

    cout << "Enter the data part"
         << " ";
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
}

void rotateList(Node *head)
{
  if (head == NULL || head->next == NULL)
    return;

  Node *temp = head;
  Node *prev = NULL;
  while (temp->next != NULL)
  {
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  // cout << temp->next << " ";
  temp->next = head;
  head = temp;
}

void display()
{
  struct Node *ptr;
  ptr = head;
  while (ptr != NULL)
  {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
}

int main()
{
  createLinkedList();
  // display();
  rotateList(head);
  display();
  return 0;
}