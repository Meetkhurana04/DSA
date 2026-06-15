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


int main() {

  node *root = new node(1);
  root->left = new node(2);
  root->left->left = new node(3);
  root->left->right = new node(4);
  root->right = new node(5);
  root->right->right = new node(7);
  root->right->left = new node(6);


  vector<int> pre;
  vector<int> post;
  vector<int> in;

  stack<pair<node*,int>> st ;
  st.push({root,1});

  while(!st.empty()){
    
      if(st.top().second==1){
        pre.push_back(st.top().first->data);
        st.top().second += 1;
        if(st.top().first->left!=NULL){
          st.push({st.top().first->left,1});
        }
      }
      else if (st.top().second == 2)
      {
        in.push_back(st.top().first->data);
        st.top().second += 1;
        if (st.top().first->right != NULL)
        {
          st.push({st.top().first->right, 1});
        }
      }
      else{
        post.push_back(st.top().first->data);
        st.pop();
      }
  }

  cout << "pre" << endl;
  for(auto it:pre){
    cout << it ;
  }
  cout << endl;

  cout << "in" << endl;
  for (auto it : in)
  {
    cout << it;
  }
  cout << endl ;
  cout << "post" << endl;
  for (auto it : post)
  {
    cout << it;
  }
}