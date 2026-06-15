#include<stdio.h>
#include<bits/stdc++.h>

using namespace std ;

struct node {
    int data ; 
    node* left ; 
    node* right ;

    node(int val){
        data = val ; 
        left = NULL ; 
        right = NULL ; 
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

   stack<node*> st ; 
   if(root==NULL){
    return 0;
   }
   st.push(root);
   while (!st.empty())
   {
       node* top = st.top();
       cout << top->data;
       st.pop();
       if (top->right != NULL)
       {
           st.push(top->right);
       }
       if (top->left != NULL)
       {
           st.push(top->left);
       }
   }

   return 0 ; 

}