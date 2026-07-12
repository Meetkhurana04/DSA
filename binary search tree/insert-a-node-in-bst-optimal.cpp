#include <iostream>
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

void preorder(node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data;
  preorder(root->left);
  preorder(root->right);
}

int main()
{
  // Root
  node *root = new node(5);

  // Left Subtree
  root->left = new node(3);
  root->left->left = new node(2);
  root->left->right = new node(4);

  // Right Subtree
  root->right = new node(7);
  root->right->left = new node(6);
  root->right->right = new node(8);
  
  int key = 9 ; 
  node *cur = root ; 
  while(true){
    if(cur->data<=key){
      if(cur->right!=NULL){//right h toh rihg tjao 
        cur = cur->right ;
      }
      else{
        // right nhi h toh whi lgado righ tme 
        cur->right = new node(key);
        break;
      }
    }
    else{
      if(cur->left !=NULL){
        cur = cur->left ; // cur cur left pe jaaayegi
      }
      else{
        cur->left = new node(key);
        break ; // whiel(treu) ke asa sr ko todne ke liye break lga h cause theris nothing stoping us 
      }

    }
  }

  preorder(root);
  // while(root) ko bhi use krskt eh ; but iske nuksan h maanlo aap last me phcuh gye nulla agya loop ruk gya apa pe aprent ka access nhi h you hav eot amintain a previous popinter in thsi case so yeh hi sb se best h while(true) wala 

  return 0;
}