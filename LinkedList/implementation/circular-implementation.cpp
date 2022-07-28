#include <iostream>
#include <map>
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
  cout << "Enter the number of node";
  cin >> n;
  while (n)
  {
    struct Node *newNode, *current;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter the data" << endl;
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

// method 1 - circular
bool isCircularList(Node *head)
{
  // empty List
  if (head == NULL)
  {
    return true;
  }
  struct Node *temp = head->next;
  while (temp != NULL && temp != head)
  {
    temp = temp->next;
  }

  if (temp == head)
  {
    return true;
  }

  return false;
}

// detect loop using extra_space map
bool detectLoop(Node *head)
{

  struct Node *temp = head;
  if (head == NULL)
    return false;

  // map
  map<Node *, bool> mp;
  while (temp != NULL)
  {
    // cycle present
    if (mp[temp] == true)
    {
      cout << "Present on element" << temp->data << endl;
      return true;
    }
    mp[temp] = true;
    temp = temp->next;
  }
  return false;
}

// floyd cycle detection algorithm
bool floydDetection(Node *head)
{

  if (head == NULL)
    return false;
  Node *slow = head;
  Node *fast = head;

  while (slow != NULL && fast != NULL)
  {
    fast = fast->next;
    if (fast != NULL)
    {
      fast = fast->next;
    }
    slow = slow->next;
    if (slow == fast)
    {
      return 1;
    }
  }
  return 0;
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
  display(head);
  if (isCircularList(head))
    cout << "LinkedList is circular in nature";
  else
    cout << "LinkedList is not circular";
}