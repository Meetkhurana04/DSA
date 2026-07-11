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

  while (root != NULL && root->data != val)// ya toh roor null hojaye yha toh miljaaye do hi option h 
  {
    root = (val < root->data) ? root->left : root->right;
  }

  return root;
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


  

  return 0;
}