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
vector<int> v;


void inorderr(node *root){

  if(root==NULL) return ; 
  inorderr(root->left);
  cout << root->data << " ";
  inorderr(root->right);
}
void inorder(node * root , int &k ){
  if (root == NULL)
    return;
  inorder(root->left,k);
  k = k - 1;
  if (k == 0)
  {
    cout << "your kth value : " << root->data;
  }
 
  inorder(root->right,k);
}



int main()
{
  // Root
  node *root = new node(5);

  // Left Subtree
  root->left = new node(3);
  root->left->left = new node(1);
  root->left->right = new node(4);

  // Right Subtree
  root->right = new node(7);
  root->right->left = new node(6);
  root->right->right = new node(8);

  // Extra Node
  root->left->left->right = new node(2);

  // i have to write a inorder , inorder mostly khud hi hota h agar isse chloge toh humara bst sorted output hi dega 
  // and merko kth element chaiye toh kth print krdunga 
  node * dummy = root ; 
  inorderr(dummy);
  dummy = root ; 
  int k = 3 ; 
  inorder(dummy,k);

  return 0;
}