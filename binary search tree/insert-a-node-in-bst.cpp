#include <iostream>
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

node *searchBST(node *root, int val)
{

  node *pre = NULL; 

  while(root){
    if (root->data == val)
      return root;
    if(root->data>val){
      pre = root ; 
      root=root->left;
    }
    else{
      pre = root;
      root=root->right;
    }

  }

  return pre ; 
}

void preorder(node *root){
  if(root==NULL){
    return ;
  }
  cout << root->data ; 
  preorder(root->left);
  preorder(root->right);
}

int main()
{
  // Root
  node *root = new node(5);

  // Left Subtree
  root->left = new node(3);
  root->left->left = new node(2);
  root->left->right = new node(4);

  // Right Subtree
  root->right = new node(7);
  root->right->left = new node(6);
  root->right->right = new node(8);

  int key = 9;
  if (root == NULL)
  {
    root = new node(key);
  }
  else {
  node *pre = searchBST(root, key);

  if (pre->data == key)
  {
    cout << "Key already exists!";
  }
  else if (key < pre->data)
  {
    pre->left = new node(key);
  }
  else
  {
    pre->right = new node(key);
  }
}

  preorder(root);




  return 0;
}