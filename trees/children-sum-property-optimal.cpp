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

vector<int> dfs(node *root, vector<int> &v)
{
  if (root == NULL)
  {
    return v;
  }
  v.push_back(root->data);
  dfs(root->left, v);
  dfs(root->right, v);

  return v;
}

int childrensum(node* root){
  if(root == NULL) return 0; 
  int child = 0 ; 
  if(root->left){
    child += root->left->data ; 
  }
  if(root->right){
    child += root->right->data ;
  } // isme kyah jo h voh child me add horha h nhi h toh nhi horah h 


  // isme woh conditon lg hri h ki child ka sum bda h root data se ; 
  // jb sum bda h toh hum equal too krdete h 
  // jb chota h ota h toh hum child ko update krte h if they exist 
  if(child >= root->data) root->data = child ;
  else {
    if(root->left) root->left->data = root ->data ; 
    else if(root->right) root->right->data = root->data ;

  }
  childrensum(root->left);
  childrensum(root->right);

  int tot = 0 ; 
  if(root->left) tot += root->left->data ; 
  if(root->right) tot += root->right->data ; 
  if(root->left || root->right) root->data = tot ; 
  
}

int main()
{
  node *root = new node(40);

  // Left Subtree
  root->left = new node(10);
  root->left->left = new node(2);
  root->left->right = new node(5);

  // Right Subtree
  root->right = new node(20);
  root->right->left = new node(30);
  root->right->right = new node(40);

  vector<int> v;
  vector<int> vv = dfs(root, v);
  for (auto it : v)
  {
    cout << it << " ";
  }
  cout << endl
       << "after " << endl;
  childrensum(root);

  vector<int> vvv;
  vector<int> vvvv = dfs(root, vvv);
  for (auto it : vvvv)
  {
    cout << it << " ";
  }

  return 0;
}