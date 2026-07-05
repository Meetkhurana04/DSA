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

bool getpath(node* root , vector<int> &path, int key){
  if (root == NULL){
    return false; 
  }
  path.push_back(root->data); // andar daalenge jese jese aage bdhenge 
  if(root->data == key) return true ; 
  
  if(getpath(root->left,path,key) || getpath(root->right,path,key))
  {
    return true ; // agar ek bhi side se true arha h toh upar true hi jaayega
  }
  path.pop_back(); //piche se nikaldo if tum glt ho 
  return false ; 
}



int main()
{
  // Creating nodes
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->left->right->left = new node(6);
  root->left->right->right = new node(7);

  vector<int> path ;
  int key = 7 ;


 if(getpath(root,path,key)) {
  cout << "path :";
  for(int x: path){
    cout << x << " ";
  }
}
  else {
    cout << "key not found ";
  }

 


}