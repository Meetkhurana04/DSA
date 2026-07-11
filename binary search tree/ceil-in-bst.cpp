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

int ceil(node* root , int target){
  int ceil = -1 ;
  if(root==NULL){
    return ceil ; 
  }

  while(root){
  if(root->data==target){
    ceil = root->data ; 
    return ceil ;
  }
  if(root->data<target){
    root=root->right;
  }
  else{
    ceil = root->data ;
    root=root->left ;
  }

}
return ceil;
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


    int target = 8 ;
    int min = ceil(root,target);
    cout << "your answer : " << min ; 


    return 0;
}