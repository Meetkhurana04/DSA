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

int floor(node *root, int target)
{
  int floor = -1;
  if (root == NULL)
  {
    return floor;
  }

  while (root)
  {
    if (root->data == target)
    {
      floor = root->data;
      return floor;
    }
    if (root->data < target)
    {
      floor = root->data;
      root = root->right;
    }
    else
    {
      
      root = root->left;
    }
  }
  return floor;
}

int main()
{
  // Root
  node *root = new node(10);

  // Left Subtree
  root->left = new node(5);
  root->left->left = new node(3);
  root->left->left->left = new node(2);
  root->left->left->right = new node(4);

  root->left->right = new node(6);
  root->left->right->right = new node(9);

  // Right Subtree
  root->right = new node(13);
  root->right->left = new node(11);
  root->right->right = new node(14);

  int target = 8;
  int min = floor(root, target);
  cout << "your answer : " << min;

  return 0;
}