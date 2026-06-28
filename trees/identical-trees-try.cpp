#include<iostream>
using namespace std ;

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

int preorder(node* root,node* root2){

  if(root == NULL &&  root2 == NULL){
    return 1 ;
  }
  if (root == NULL || root2 == NULL)
  {
    return 0;
  }
  if(root->data == root2->data){
    int left = preorder(root->left,root2->left);
    int right = preorder(root->right,root2->right);

    return left && right ; 
  }
  else{
      return 0 ;
  }
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



  node *root2 = new node(0);

  // Level 1
  root2->left = new node(2);
  root2->right = new node(3);

  // Level 2
  root2->right->left = new node(4);
  root2->right->right = new node(6);

  // Level 3
  root2->right->left->left = new node(5);
  root2->right->right->right = new node(7);

  // Level 4
  root2->right->left->left->left = new node(9);
  root2->right->right->right->right = new node(8);

  // pre order kya hota h pre order hota h ki root left right
  int meet = preorder(root, root2);
  if(meet == 0){
    cout << "dont identical";
  }
  else{
    cout << "idenitcal";
  }
  
  
  return 0;
}
