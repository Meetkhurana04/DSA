#include <iostream>
#include<bits/stdc++.h>
#include<cmath>
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

int countnodes(node *root){
  int lh = 0 ; 
  int rh = 0 ; 
  if(NULL == root){
    return 0 ; 
  }
 
node *temp = root;

while(temp){
    lh++;
    temp = temp->left;
}
temp = root;

while (temp)
{
  rh++;
  temp = temp->right;
}
if(lh == rh){
  // its a perfect tree ; 
  // return pow(2,lh) - 1 ; 
  return (1 << lh) - 1 ; 
  // shitf integer operation faster h , mtlb yeh power lgadega pta bhi nhi chlega
}
return 1 + countnodes(root->left) + countnodes(root->right);
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

  cout << "total number of count : " << countnodes(root);

  return 0;

  
}

