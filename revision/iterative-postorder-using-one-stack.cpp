// jitna deep left me jaskte h jayenge postorder h na toh left irgh root hoga hum left me hi deep me jaayenge jha atkenge wha right me jaayenge ; and then so on jb hum pop krte huye wapis arhe honge tb print kr rhe honge

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

// do triek hote h while st.empty or while true st.empty hi use hota h 
  stack<node*> st ; 
  node* curr = root;
  st.push(curr); 
  while(!st.empty()){
    if(curr!=NULL){
      curr = curr->left ;
      st.push(curr);
    }
    else{
      node* temp = st.top()->right;
      if(temp==NULL){
          temp = st.top();
          st.pop();
          cout << temp->data ;
          while(!st.empty() && temp==st.top()->right){

          } 
      }
      else{
        curr = temp ; //ise kya hoga left ki jgh right me hojayega 
      }


    }


  }


}


