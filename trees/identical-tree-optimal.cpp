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


bool preorder(node* p , node* q){
  if(p==NULL || q==NULL){
    return (p==q); // toh yeh dono case hindle krdega either p or q dono case handle hojayenge 
  }
  return (p->data == q->data) && preorder(p->left, q->left) && preorder(p->right, q->right) ;
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
  root2->right->right->right->right = new node(7);

  // pre order kya hota h pre order hota h ki root left right
  int m = preorder(root,root2);
  if (m==0){
    cout << "unidentical";
  }
  if (m==1){
    cout << "identical";
  }
  return 0;
}
