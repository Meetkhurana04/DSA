#include <iostream>
#include<bits/stdc++.h>
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


int main(){
  queue<node*> q ; 
  stack<vector<int>> st ;
  
  node* root = new node(1);
  root->left = new node(2);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right = new node(3);
  root->right->right = new node(6);


   int flag = 0 ; 

   q.push(root);

   
   while(!q.empty()){ // jb tk empty nhi h aapko chlna h
     vector<int> level;
    int size = q.size() ; 
    for(int i = 0 ; i < size ; i++){
      node* temp = q.front();
        q.pop();
     if(flag == 0 ){
     if (temp->left != NULL)
     {
       q.push(temp->left);
     }
   if(temp->right!=NULL)
   {
    q.push(temp->right);

   }
   flag = 1; 
  }
   if(flag == 1 ){
     if (temp->left != NULL)
     {
       q.push(temp->left);
     }
   if(temp->right!=NULL)
   {
    q.push(temp->right);

   }
   flag = 0; 
  }
   level.push_back(temp->data);
  }
  st.push(level);
}


  
}