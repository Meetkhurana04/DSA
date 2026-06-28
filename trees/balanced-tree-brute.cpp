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

// balanced tree me merkeo har time pe balanced factor check krna h uske liye mereko hight bta honi chaiye us level pe left or right ki lets phel height napne ka code likhte h

int height(node* root){
  if(root == NULL){
    return 0 ; 
  }
  int rh = height(root->right);
  int lh = height(root->left);

  return max(lh,rh)+1 ;

}

bool balancedtree(node* root){
  if(root == NULL){
    return true ;
  }
  int lh = height(root->left);
  int rh = height(root->right);

  if(abs(rh-lh)>1){
    return false ;
  }
  bool left = balancedtree(root->left);
  bool right = balancedtree(root->right);

  if(!left || !right ) return false ; 

  return true ; 
  
}

int main()
{
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->right->left = new node(4);
  root->right->right = new node(6);

  root->right->left->left = new node(5);
 
  cout << balancedtree(root);
  
}
