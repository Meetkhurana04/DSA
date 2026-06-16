#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
struct node
{
  int data;
  node *right;
  node *left;

  node(int val)
  {
    data = val;
    right = NULL;
    left = NULL;
  }
};

int postorder(node* root){
  // if(root==NULL){
  //   return 0;
  // }
  
  postorder(root->left);
  postorder(root->right);
  cout << root->data;
}



int main(){

  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->right->left = new node(6);
  root->right->right = new node(7);


  // root left right 
  postorder(root);
 

}