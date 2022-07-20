#include <iostream>
#include <stack>
using namespace std;

int main()
{

  // creation of stack using stl
  stack<int> st;

  // push operation
  st.push(2);
  st.push(3);

  // pop operation
  st.pop();

  cout << "Print the top of element " << st.top() << endl;

  if (st.empty())
  {
    cout << "Stack is empty";
  }
  else
  {
    cout << "stack not empty";
  }
  return 0;
}