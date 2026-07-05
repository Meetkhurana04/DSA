#include <bits/stdc++.h>
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
vector<vector<int>> v ; 
queue<node* > q ;

bool sym(node* right,node* left){
   if (right == NULL || left == NULL) {
        return right==left ;
   }
  if(right->data != left->data){
    return false ;
  }
  
  return sym(right->right , left->left) && sym(right->left , left->right );
  
}

int main()
{
  // Root
  node *root = new node(1);

  // Level 1
  root->left = new node(2);
  root->right = new node(2);

  // Level 2
  root->left->left = new node(3);
  root->left->right = new node(4);

  root->right->left = new node(4);
  root->right->right = new node(3);

  


  bool meet = sym(root->left,root->right);
  if(meet == true){
    cout << "it is symmetric";
  }
  else {
    cout << "is not";
  }
}