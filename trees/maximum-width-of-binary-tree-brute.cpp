#include <iostream>
#include<bits/stdc++.h>
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

int maxwidth(node* root){
  if (root == NULL)
    return 0;
  queue<pair<node*,unsigned long long>> q ; 
  q.push({root,0});
  int maxwidht = 0 ; 

  while(!q.empty()){
    int curlevelsize = q.size() ; 
    unsigned long long stdindex = q.front().second ;
    unsigned long long endindex = q.back().second ; 

    maxwidht = max(maxwidht ,(int)(endindex - stdindex + 1));
    for(int i = 0 ; i < curlevelsize ; i ++){
      auto curr = q.front() ; 
      q.pop();
      if(curr.first->left){
        q.push({curr.first->left,curr.second*2+1});
      }
      if(curr.first->right){
        q.push({curr.first->right, curr.second * 2 + 2});
      }
    }

  }

  return maxwidht ; 


}



int main()
{
  // Creating Tree
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->left->right->left = new node(6);
  root->left->right->right = new node(7);

  cout << "answer : " << maxwidth(root) ; 

  
}

