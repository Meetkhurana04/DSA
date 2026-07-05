#include <iostream>
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
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->right->right = new node(7);

  root->left->right->left = new node(8);
  root->left->right->right = new node(9);

  map<int, int> mp;
  queue<pair<node*,int>> q ;
  

  q.push({root,0});

  while(!q.empty()){
    node* temp = q.front().first;
    int x = q.front().second ; 
    q.pop();
    mp[x]=temp->data;
    if(temp->left!=NULL){
      q.push({temp->left,x-1});

    }
    if(temp->right!=NULL){
      q.push({temp->right, x + 1});
    }
  }

  for(auto it : mp){
    cout << it.second << endl ;
  }

  return 0;


}