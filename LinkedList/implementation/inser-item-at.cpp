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
  int n;
  cout << "Enter the number of nodes"
       << " ";
  cin >> n;
  struct Node *newNode, *current;

  while (n)
  {
    newNode = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter the Data"
         << " ";
    cin >> newNode->data;
    newNode->next = NULL;
    if (head == NULL)
      head = newNode;
    else
      current->next = newNode;
    current = newNode;
    --n;
  }
}

// insert item at first node
void insertAtFirst()
{
  struct Node *newNode;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  cout << "Enter the data you want to insert at first"
       << " ";
  cin >> newNode->data;
  if (newNode == NULL)
  {
    cout << "Memory Error";
    return;
  }
  newNode->next = head;
  head = newNode;
}

// insert element at the end of the linked list
void insertAtLast()
{
  struct Node *newNode, *current = head;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  cout << "Enter the data you want to last"
       << " ";
  cin >> newNode->data;
  newNode->next = NULL;
  if (newNode == NULL)
  {
    cout << "Memory Error";
    return;
  }

  while (current->next != NULL)
    current = current->next;
  current->next = newNode;
}

// insert at between postion befor given data
void insertAtBetween(int y)
{
  struct Node *newNode, *current, *prev;
  current = head;
  while (current->next != NULL && current->data != y)
  {
    prev = current;
    current = current->next;
  }
  if (current == NULL)
  {
    cout << "Insertion Not Possible";
    return;
  }
  newNode = (struct Node *)malloc(sizeof(struct Node));
  cout << "Enter the data of new node";
  cin >> newNode->data;
  if (current == head)
  {
    newNode->next = current;
    head = newNode;
  }
  else
  {
    newNode->next = current;
    prev->next = newNode;
  }
}

void display(struct Node *start)
{
  start = head;
  while (start)
  {
    cout << start->data << " ";
    start = start->next;
  }
}

int main()
{
  createList();
  cout << "List is"
       << " ";
  display(head);
  cout << endl;
  insertAtFirst();
  cout << "Insert data at first postion" << endl;
  display(head);
  cout << endl;
  insertAtLast();
  cout << "Insert data at last postion" << endl;
  display(head);
  cout << endl;
  int x;
  cout << "Enter the element to check";
  cin >> x;
  insertAtBetween(x);
  cout << "Insert data at last postion" << endl;
  display(head);
}