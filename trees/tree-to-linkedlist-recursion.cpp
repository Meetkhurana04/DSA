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

node* prevv = NULL;
void flatten(node* root){
  
  if(root==NULL){
    return;
  }
  flatten(root->right);
  flatten(root->left);
  root->right = prevv ;
  root->left = NULL ;
  prevv = root ; 


}

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

    flatten(root);

    while (root)
    {
      cout << root->data;
      root = root->right;
    }

    return 0;
}