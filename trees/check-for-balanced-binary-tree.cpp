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

int bf(node* root){
  if(root == NULL){
    return 0 ; 
  }
  int lh = bf(root->left);
  int rh = bf(root->right);

  return 1 + max(lh,rh);;

}
int checkbf(node* root){

  if(root==NULL){
    return 0 ;
  }

  int rsize = bf(root->right);
  int lsize = bf(root->left);

  int bff = lsize - rsize;

  if (bff >= -1 && bff <= 1)
  {
    return checkbf(root->left) && checkbf(root->right);
  }
  else
  {
    return 0;
  }
}


int main()
{
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->right->left = new node(4);
  root->right->right = new node(6);

  root->right->left->left = new node(5);
 
  cout << checkbf(root);


}

