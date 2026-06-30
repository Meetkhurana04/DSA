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
bool isleaf(node *root)
{
  return root->left == NULL && root->right == NULL;
}

void addleft(node* root , vector<int> &res){
  node* cur = root->left ; 
  while(cur){
    if(!isleaf(cur)){
      res.push_back(cur->data);
    }
    if(cur->left){
      cur=cur->left;
    }
    else{
      cur=cur->right;    
    }
  }
}

void addright(node* root , vector<int> &res){
  node * cur = root->right; 
  vector<int> temp ; 
  while(cur){
    if(!isleaf(cur)) temp.push_back(cur->data);
    if(cur->right) cur = cur->right ; 
    else cur = cur -> left ; 
  }
  for(int i = temp.size()-1; i >=0 ; --i){
    res.push_back(temp[i]);
  }

}

void addleaves(node *root , vector<int>&res){
  if(isleaf(root)){
    res.push_back(root->data);
    return ; 
  }
  if(root->left)addleaves(root->left,res);
  if(root->right)addleaves(root->right,res);
}



int main() {

  stack<node*> st;
  queue<node*> q;
  vector<int> ans ; 
  node *root = new node(1);

  root->left = new node(2);
  root->left->left = new node(3);
  root->left->left->right = new node(4);

  root->left->left->right->left = new node(5);
  root->left->left->right->right = new node(6);

  root->right = new node(7);
  root->right->right = new node(8);

  root->right->right->left = new node(9);

  root->right->right->left->left = new node(10);
  root->right->right->left->right = new node(11);

  vector<int> res;
  if(!root) return 0; 
  if(!isleaf(root)) res.push_back(root->data);
  addleft(root,res);
  addleaves(root,res);
  addright(root,res);
  for(auto x : res){
    cout << x << " ";
  }
  return 0 ; 

}