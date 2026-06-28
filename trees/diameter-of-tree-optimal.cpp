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
int size = 0 ; 
int h(node* root){
  if(root == NULL){
    return 0 ; 
  }

  int lh = h(root->left);
  int rh = h(root->right);

  // agar m yhi pe kuch krlu toh optimal hojayega find diameter ka ; 
  size = max(lh+rh+1,size);

  return max(lh,rh) + 1 ; 
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

  h(root);
  cout << size ; 

  return 0;

}
