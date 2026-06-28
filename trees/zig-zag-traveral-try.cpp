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

   while (!q.empty())
   {

     vector<int> level;

     int size = q.size();

     if (flag == 0)
     {
       for (int i = 0; i < size; i++)
       {
         node *temp = q.front();
         q.pop();

         if (temp->left)
           q.push(temp->left);

         if (temp->right)
           q.push(temp->right);

         level.push_back(temp->data);
       }

       flag = 1; // yaha
     }

     else
     {
       for (int i = 0; i < size; i++)
       {
         node *temp = q.front();
         q.pop();

         if (temp->left)
           q.push(temp->left);  // yeh part toh commn h toh fir loop me kyu h // toh isko toh mene glt hi wrap kiya h konsa me ulta kr rha hu 

         if (temp->right)
           q.push(temp->right);

         level.insert(level.begin(), temp->data);
       }
       flag = 0; // yaha
     }

     st.push(level);
   }

while(!st.empty()){
  auto it = st.top();
  st.pop();
  for(auto i : it){
    cout << i ; 
  }
  cout << endl;
}


  
}