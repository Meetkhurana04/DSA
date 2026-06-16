#include<stdio.h>
#include<bits/stdc++.h>

using namespace std ;
struct node{
  int data ; 
  node* right ;
  node* left ;

  node(int val){
    data = val;
    right = NULL ;
    left = NULL ;
  }
};
int main() {
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->right->left = new node(6);
  root->right->right = new node(7);

  queue<node*> q  ;
  vector<vector<int>> push ; 

  // hume kyakrna h bfs krna h breadfirst search phle ek ko dekhna h uske baad ;
  
  q.push(root);
  while(!q.empty())
  {
    int size = q.size();
    vector<int> level ; 

    for(int i = 0 ; i < size ;i++){
      node* root = q.front() ;
      q.pop();// pop kiya or uske bche daale 
      if(root->left!=NULL){
        q.push(root->left);
      }
      if(root->right!=NULL){
        q.push(root->right);
      }

      level.push_back(root->data);
    }
    push.push_back(level);



  }

  for (auto it : push)
  {
    for (auto x : it)
    {
      cout << x << " " ;
    }
    cout << endl;
  }
  cout << "depth of tree" << endl ;
  cout << push.size() ;
  
}