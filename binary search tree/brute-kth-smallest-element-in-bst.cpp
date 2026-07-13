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
vector<int> v ; 

void preorder(node *root)
{
  if (root == NULL)
    return;
  v.push_back(root->data);

  
  preorder(root->left);
  preorder(root->right);
}

vector<int> sort(vector<int> v){
  int mini = INT_MAX ;
  int n = v.size() ;

  for(int i = 0 ; i < n-2 ; i++){
    int mini = i ; // phle element ko hi minimum maan lete h 
    for(int j = i ; j < n-1 ; j++){ // i se n-1 tka chlte h 
        if(v[j]<v[mini]){
          mini = j ;  // naya minimum milne par index update krta h ; [3]

        //  hum index store kr rhe h jis se swapping kar paay 
        }

        // swapping minimum element ko sahi jagah par swap krna h 
        int temp = v[mini];
        v[mini]=v[i];
        v[i]=temp ;

    }
    
  }
  return v ; 

}

int main()
{
  // Root
  node *root = new node(5);

  // Left Subtree
  root->left = new node(3);
  root->left->left = new node(1);
  root->left->right = new node(4);

  // Right Subtree
  root->right = new node(7);
  root->right->left = new node(6);
  root->right->right = new node(8);

  // Extra Node
  root->left->left->right = new node(2);

  cout << "Preorder Traversal: ";
  preorder(root);

  for(auto it : v ){
    cout << it << " "; 
  }

  vector<int> newv = sort(v);
  cout << endl << "after :" << endl ;
  for(auto it:newv){
    cout << it << " " ;
  }

  cout << endl << "kth largest element" << endl ;
  cout << v[3];

  return 0;
}