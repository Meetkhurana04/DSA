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


// without changing tree strucutre hum krte h yeh 

void markparents(node * root, unordered_map<node*,node*> &parent ){
  queue<node*>q ; 
  q.push(root);

  while(!q.empty()){
    node* current = q.front();
    q.pop() ;
    if(current->left){
      parent[current->left] = current ; 
      q.push(current->left);
    }
    if(current->right){
      parent[current->right] = current ; 
      q.push(current->right);
    }
  }
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

  int k = 2 ; 
  
  unordered_map<node* , node*> parent ; 
  markparents(root,parent);

  unordered_map<node *, bool> visited;
  queue<node*> q ;
  q.push(target) ;
  visited[target]=true ; 
  int curr_level = 0 ; 

  while(!q.empty()){
    // jb tk queue empty nhi h bfs chlega 
    int size = q.size() ; // curretn level ke nodes ki count btata h 
    if(curr_level++ == k) break ;  // iska mtlb h k tk chlna h aapko fir ruk jana h 
    // yeh queue ko exccess me bhrne se rokega agar excess me bhroge nhi toh fir traversal hoga or chij chlti rhegi yeh k wali thing rokne me mdad kregi 
    for(int i = 0 ; i < size;i++){
      node * curr = q.front() ;
      q.pop() ;
      if (curr->left && !visited[curr->left])
      {
        q.push(curr->left);
        visited[curr->left] = true;
      }
      if (curr->right && !visited[curr->right])
      {
        q.push(curr->right);
        visited[curr->right] = true;
      }
      if (parent[curr] && !visited[parent[curr]])
      {
        q.push(parent[curr]);
        visited[parent[curr]] = true;
      }
    }
  }

  while (!q.empty())
  {
    cout << q.front()->data << " ";

    q.pop();
  }

}