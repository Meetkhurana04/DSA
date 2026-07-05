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
int key = 7  ;
int f =0 ;
map<int,int> mp ; 

bool traverse(node* root){
  if (root == NULL)
  {
    return false;
  }
  if (root->data==key){
    mp[root->data]=1 ; 
    return true ; 
  }
  
  bool left = traverse(root->left);
  bool right = traverse(root->right);

  if (left || right)
  {
    mp[root->data] = 1;
    return true ; 
  }
  return false ; 
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

  
  traverse(root);
  for(auto it : mp ){
    cout << it.first << ":" << it.second << endl; 
  }

  return 0;
  // q.push(root);
  // while(!q.empty()){
  //   node* temp = q.front() ; 
  //   mp[temp->data] = 1 ;
  //   q.pop() ;
  //   if (temp->right != NULL && temp->left != NULL){
  //     mp[temp->data] = 0;
  //   }

  //     if (temp->right != NULL)
  //     {
  //       q.push(root->right);
  //     }
  //   if (temp->left != NULL)
  //   {
  //     q.push(root->left);
  //   }
  
  // }
}