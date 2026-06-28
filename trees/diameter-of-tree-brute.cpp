#include <iostream>
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

int height(node* root){

  if(root == NULL){
    return 0 ; 
  }
  int lh = height(root->left);
  int rh = height(root->right);

  return max(lh,rh)+1 ;

}
int size = 0 ;
int checkd(node* root){
  if(root == NULL){
    return 0 ; 
  }

  int lh = height(root->left);
  int rh = height(root->right);

  size = max(size,lh+rh);

  checkd(root->left);
  checkd(root->right);

  return size ; 
}
int main()
{
  // Root
  node *root = new node(0);

  // Level 1
  root->left = new node(2);
  root->right = new node(3);

  // Level 2
  root->right->left = new node(4);
  root->right->right = new node(6);

  // Level 3
  root->right->left->left = new node(5);
  root->right->right->right = new node(7);

  // Level 4
  root->right->left->left->left = new node(9);
  root->right->right->right->right = new node(8);

  cout << checkd(root);

  return 0;
}
// but 0n2 hojayega