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

int height(node * root){
  if(root == NULL){
    return 0 ; 
  }

  int lh = height(root->left);
  int rh = height(root->right);
  // isme hi hume kuch likhna h ; 
  if(lh==-1 && rh==-1) {
    return -1 ;
  }
  if(abs(lh-rh)>1){
    return -1 ; 
  }

  return max(lh,rh) + 1 ;
}

int main()
{
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->right->left = new node(4);
  root->right->right = new node(6);

  root->right->left->left = new node(5);

  // hume optimal krna h optimal aata h height wale se toh hum try krte h phel height wala hi likhe 

  cout << height(root);

  

}
