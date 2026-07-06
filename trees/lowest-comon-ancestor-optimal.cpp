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


int getpath(node* root , int key1 , int key2 ){
  
  if(root==NULL){
    return -1 ; 
  }
  // if(f!=-1){
  //   return f ; 
  // }
  if(root->data == key1 || root->data == key2){
    return root->data ; 
  }
  if(root->right==NULL && root->left==NULL){
    return -1 ; 
  }
  
  
  
  int left = getpath(root->left, key1, key2);
  int right = getpath(root->right,key1,key2);

  if(right != -1 && left != -1){// dono side key mili 
    return root->data; 
  }
  // Sirf left me mili
  if (left != -1)
    return left;

  // Sirf right me mili
  if (right != -1)
    return right;

  // Kahin nahi mili
  return -1;
}

int main()
{
  // Creating nodes
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->left->right->left = new node(6);
  root->left->right->right = new node(7);
  int k1 = 4 ; 
  int k2 = 7 ;
  int f = -1;

  // dfs traversal krte h
  cout << "your answer : " << getpath(root, k2, k1);
}