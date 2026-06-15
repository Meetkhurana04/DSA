#include <stdio.h>
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
  node *root = new node(1);
  root->left = new node(2);
  node *two = root->left;
  two->left = new node(3);
  two->right = new node(4);
  two->right->left = new node(5);
  two->right->right = new node(6);
  root->right = new node(7);
   
  stack<node*> st1 ; 
  stack<node*> st2 ; 
  node* curr = root;
  st1.push(curr);
  while(!st1.empty()){
   
    node* top = st1.top() ; 
    st2.push(top);
    st1.pop() ; 
    if(top->left!=NULL){
      st1.push(top->left);
    }
    if (top->right != NULL)
    {
      st1.push(top->right);
    }
    
  }


  while(!st2.empty()){
    node* curr = st2.top() ; 
    cout << curr->data << " "; 
    st2.pop();
    
  
  }
}