#include <iostream>
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
  // Nodes create
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->left->right->left = new node(6);

  root->right->right = new node(7);
  map<int,int> mp ; 
  queue<pair<node*,int>> q ; 

  if(root==NULL){
    return 0; 
  }

  q.push({root,0});

  while(!q.empty()){
    node* temp = q.front().first ; 
    int x = q.front().second ;
    int key = x ; 
    if(mp.find(key)==mp.end()){
      mp[key]=temp->data;
    } 
    q.pop() ; 
    if(temp->left!=NULL){
      q.push({temp->left,x - 1});
    }
    if (temp->right != NULL){
      q.push({temp->right, x + 1});
    }
  }


  for(auto it : mp){
    cout << it.first << "=" << it.second << endl ; 
  }

  return 0;
}