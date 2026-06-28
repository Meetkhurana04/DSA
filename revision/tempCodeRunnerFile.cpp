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
int main()
{
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->right->left = new node(6);
  root->right->right = new node(7);

  // preorder kya hota h root left right 1 2 4 5 3 6 7
  // postorder left right root 4 5 2 6 7 3 1
  // inorder left root right 4 2 5 1 6 3 7
  // toh mujhko stack use hoga isme woh bhi ek 
  stack <node*> st ;
  // manlete h jese hi aata h stack me push kiya print kiya push kiya print kiya left me gye push kiya print kiya or left me kiye // jese hi null aye pop kro right pe jaao if left poossible h left pe jao nhi h toh righ tpe jao
  st.push(root);
  vector<int> push ;
  push.push_back(root->data);
  while(!st.empty()){
    if(root->left!=NULL){
      root = st.top()->left ;
      st.push(root);
      push.push_back(root->data);

    }
    else{
      st.pop();
      st.top()->left = NULL ;
      if(st.empty()){
        break; 
      }
      root=st.top()->right;
      st.push(root);
      push.push_back(root->data);
    }
  }
  
for(auto it:push){
  cout << it ;
}


}