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

vector<int> bfs(node*root, vector<int> &v){
  if(root == NULL){
    return v; 
  }
  v.push_back(root->data);
  bfs(root->left,v);
  bfs(root->right,v);
  

  return v ; 
}

int childrensum(node* root){
  if(root ==  NULL){
    return 0 ; 
  }
  if(root->left!=NULL && root->right!=NULL){
    if(root->left->data + root->right->data < root->data){
      root->left->data = root->data ;
      root->right->data = root->data ; 
    }
    else{
      root->data = root->left->data + root->right->data ; 
    }
  
  int left = childrensum(root->left);
  int right = childrensum(root->right);
  
  root->data = root->left->data + root->right->data;
  }
  return root->data ;
}
int main()
{
  node *root = new node(40);

  // Left Subtree
  root->left = new node(10);
  root->left->left = new node(2);
  root->left->right = new node(5);

  // Right Subtree
  root->right = new node(20);
  root->right->left = new node(30);
  root->right->right = new node(40);

  vector<int> v ; 
  vector<int> vv = bfs(root,v);
  for(auto it : v){
    cout << it << " ";
  }
  cout << endl << "after " << endl ;
  childrensum(root);

  vector<int> vvv;
  vector<int> vvvv = bfs(root, vvv);
  for (auto it : vvvv)
  {
    cout << it << " ";
  }

  return 0;
}