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
}

// detect loop
Node *floydDetection(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  while (slow != NULL && fast != NULL)
  {
    fast = fast->next;
    while (fast != NULL)
    {
      fast = fast->next;
    }
    slow = slow->next;
    if (slow == fast)
    {
      return slow;
    }
  }
  return 0;
}

// starting node of loop in a cycle
Node *getStartingNodeOfCycle(Node *head)
{
  if (head == NULL)
    return NULL;
  Node *intersection = floydDetection(head);
  Node *slow = head;
  while (slow != intersection)
  {
    slow = slow->next;
    intersection = intersection->next;
  }
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
  /* Create a loop for testing */
  head->next->next->next = head->next->next;

  if (floydDetection(head) == false)
    printf("Loop does not exist");
  else
    printf("Loop starting node is");
  return 0;
}