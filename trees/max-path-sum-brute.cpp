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
int h(node *root)
{
  if(root == NULL){
    return 0 ; 
  }
  
int lh = max(0,h(root->left));
// agar glti se - arh ahoga oth yeh use 0 krdega
int rh = max(0,h(root->right));

size = max(size , lh + rh + root->data);
// yeh actual calculate kr rha h 

return root->data + max(lh,rh);
// yeh calculate krke return kr rh ah or chose kr rh left wala le ya riogh wal 

}

//apko har level pe jana h or uske sum ka nikalna h 

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
