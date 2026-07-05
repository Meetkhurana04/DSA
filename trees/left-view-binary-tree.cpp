#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;

  node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};
stack<int> st;

int recursion(node *root, int level)
{

  if (root == NULL)
  {
    return 0;
  }
  if (level == st.size())
  {
    st.push(root->data);
  }
  
  recursion(root->left, level + 1);
  recursion(root->right, level + 1);
}

int main()
{
  node *root = new node(1);
  // Level 1
  root->left = new node(2);
  root->right = new node(3);
  // Level 2
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->right = new node(7);

  // Level 3
  root->left->right->left = new node(6);

  recursion(root, 0);

  while (!st.empty())
  {
    int temp = st.top();
    cout << temp << endl;
    st.pop();
  }
}