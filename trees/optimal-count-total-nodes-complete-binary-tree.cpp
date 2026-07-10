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

// Find Left Height
int findHeightLeft(node *root)
{
  int height = 0;

  while (root)
  {
    height++;
    root = root->left;
  }

  return height;
}

// Find Right Height
int findHeightRight(node *root)
{
  int height = 0;

  while (root)
  {
    height++;
    root = root->right;
  }

  return height;
}

// Count Nodes
int countNodes(node *root)
{
  if (root == NULL)
    return 0;

  int lh = findHeightLeft(root);
  int rh = findHeightRight(root);

  // Perfect Binary Tree
  if (lh == rh)
    return (1 << lh) - 1;

  // Otherwise recurse
  return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
  // Root
  node *root = new node(1);

  // Level 1
  root->left = new node(2);
  root->right = new node(3);

  // Level 2
  root->left->left = new node(4);
  root->left->right = new node(5);

  root->right->left = new node(6);
  root->right->right = new node(7);

  // Level 3
  root->left->left->left = new node(8);
  root->left->left->right = new node(9);

  root->left->right->left = new node(10);
  root->left->right->right = new node(11);

  cout << "Total Nodes = " << countNodes(root);

  return 0;
}