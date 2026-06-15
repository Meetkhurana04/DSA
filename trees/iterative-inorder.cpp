#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 


struct node{
    int data ;
    node* right ; 
    node* left;
    
    node(int val){
      data = val ;
      right = NULL ; 
      left = NULL ; 
    }
};

int main() {
   node* root = new node(1);
    root->left = new node(2);
    node* two = root->left ; 
    two->left = new node(3);
    two->right = new node(4);
    two->right->left = new node(5);
    two->right->right = new node(6);
    root->right = new node(7);
    
    node* curr = root ;
    vector<int> inorder;
    stack<node*> st ;
    
    while(true){
      if(curr!=NULL){
        st.push(curr);
        curr=curr->left;
      }
      else{
        if(st.empty()==true) break ;
        curr=st.top();
        inorder.push_back(curr->data);
        st.pop();
        curr = curr->right ; 
      }

    }

for(int it : inorder)
{
cout << it ; 
}
}
