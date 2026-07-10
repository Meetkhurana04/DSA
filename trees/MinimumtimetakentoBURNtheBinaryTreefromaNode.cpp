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
map<node *, node *> makeparent(node *root)
{
  map<node *, node *> parent ; 
  queue<node*> q ; 
  if(root==NULL){
    return parent ;
  }
  q.push(root);
  while(!q.empty()){
  node * curr = q.front() ; 
  q.pop();
  if(curr->left){
    parent[curr->left] = curr;
    q.push(curr->left);
  }
  if(curr->right){
    parent[curr->right] = curr;
    q.push(curr->right);
  }
}
return parent ;  
}
int burntree(node *root, node* target)

{
  int k = 0;
  map<node *, node *> parent = makeparent(root);
  map<node*,bool> vis ; 
  queue<node *> q ; 
  if(root == NULL) return 0 ; 
  q.push(target);
 
  vis[target]=true ;
  while(!q.empty()){
    int size = q.size() ; 
    bool burn = false ; 
    for(int i = 0 ; i < size ; i ++){
    node * curr = q.front() ; 
    q.pop() ;
    if (curr->left && !vis[curr->left])
    {
      q.push(curr->left) ; 
      vis[curr->left]=true ;
      burn = true;
    }
    if (curr->right && !vis[curr->right])
    {
      q.push(curr->right);
      vis[curr->right] = true;
      burn = true;
    }
    if(parent[curr] && !vis[parent[curr]]){
      q.push(parent[curr]);
      vis[parent[curr]] = true;
      burn = true;
    }
  }
  if(burn){
    k++ ; 
  }

}

  return k ; 
}

int main()
{
  node *root = new node(40);

  // Left Subtree
  root->left = new node(10);
  root->left->left = new node(2);
  root->left->right = new node(5);
  node * target = root->left->right ;

  // Right Subtree
  root->right = new node(20);
  root->right->left = new node(30);
  root->right->right = new node(40);

  // first we make parent

  
  int k = burntree(root,target);
  cout << "time taken : " << k ;

}