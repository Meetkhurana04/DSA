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

int main()
{
  // Root
  node *root = new node(1);

  // Left Subtree
  root->left = new node(2);
  root->left->left = new node(3);
  root->left->right = new node(4);

  // Right Subtree
  root->right = new node(5);
  root->right->right = new node(6);
  root->right->right->left = new node(7);

  stack<node*> st ; 
  st.push(root);
  while(!st.empty()){
    node* curr = st.top() ; 
    st.pop() ; 
    if(curr->right){
      st.push(curr->right);
    }
    if(curr->left){
      st.push(curr->left);
    }
    if(!st.empty()){
    curr->right=st.top();
    }
    curr->left=NULL ;

  }


  while(root){
    cout << root->data;
    root=root->right;
  }

  return 0;
}