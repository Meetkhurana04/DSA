#include <stdio.h>
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


int main()
{
  node* root = new node(1);
  root->left = new node(2);
  root->left->left = new node(3);
  node* three = root->left->left ; 
  three->right = new node(4);
  three->right->right = new node(5);
  three->right->right->right= new node(6);
  root->right = new node(7);
  root->right->left = new node(8);
  root->right->right = new node(9);
  root->right->right->right = new node(10);


  stack<node*> st ;
  vector<int> postorder ;
  node *cur = root ; 
  while(cur!=NULL || !st.empty()){
    if(cur!=NULL){
      st.push(cur);
      cur = cur->left ;
    }
    else {
      node *top = st.top();
      node* temp = top->right ; 
      if(temp==NULL){
        //mtlb right bhi khtm hogye h you need to pop and push into vector ;
        temp = st.top();
        postorder.push_back(temp->data);
        st.pop();
        while(!st.empty() && temp==st.top()->right){
          temp = st.top() ;
          st.pop() ;
          postorder.push_back(temp->data);
          //piche laao
        }
      }
      else{
        cur = temp ; // aage bdhao
      }
    }
  }

  for(auto it : postorder){
    cout << it ;
  }
}