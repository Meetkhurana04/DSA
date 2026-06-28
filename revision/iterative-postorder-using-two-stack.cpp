#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ;

struct node{
  int data ; 
  node* right ; 
  node* left ;

  node(int val)
    {
    data = val ; 
    right = NULL ;
    left = NULL ;
  }
};

int main() {

  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->right->left = new node(6);
  root->right->right = new node(7);

  stack<node*> st1 ; 
  stack<node*> st2 ;
  node* curr = root ; 
  st1.push(curr);
  while(!st1.empty()){
    curr=st1.top() ;
    
    st2.push(curr);
    st1.pop();
    if(curr->left!=NULL){
      st1.push(curr->left);
    }
    if(curr->right!=NULL){
      st1.push(curr->right);
    }
  }

  while(!st2.empty()){
    cout << st2.top()->data << " ";
    st2.pop();
  }
}