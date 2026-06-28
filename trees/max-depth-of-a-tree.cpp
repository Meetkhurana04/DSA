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

int maxdepth(node* root){
    if(root==NULL){
      return 0  ; //yeh toh base condition h jo shi me koi integer derha hoga 
    }
    int lh = maxdepth(root->left);// left side jao
    int rh = maxdepth(root->right);// right side jao 

    return 1 + max(lh,rh);//saare call ko 1 + krke value dega 
   
   
    
}



int main(){
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->right->left = new node(4);
  root->right->right = new node(6);

  root->right->left->left = new node(5);

  cout << maxdepth(root);

  
}