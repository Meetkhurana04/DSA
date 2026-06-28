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

int postorder(node* root){
  if(root==NULL){ // yeh sbse main h yeh na rha toh voh ek hi jgh ruk jaayega like ki pura skewedly niche jaake null milega fir woh backtrack nhi krega asli me backtrack kuch nhi hota but use kuch return ka nhi milega ki mera kaam hochuka h ab agle line pe jaao woh nhi hopayega 
    return 0;
  }
  
  postorder(root->left);
  postorder(root->right);
  cout << root->data; // yeh ko first me krdo pre hojayega ; last me krdo post bich me krdo in
}



int main(){

  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->right->left = new node(6);
  root->right->right = new node(7);


  // root left right 
  postorder(root);
 

}