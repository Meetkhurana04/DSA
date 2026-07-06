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

  vector<int> path2;
  int key2 = 4;

  if (getpath(root, path2, key2))
  {
    cout << "path :";
    for (int x : path2)
    {
      cout << x << " ";
    }
  }
  else
  {
    cout << "key not found ";
  }
  // 1 2 5 7 
  // 1 2 4  
   
  int i = 0 ;
  int j = 0 ;

  int x = path.size() ; 
  int y = path2.size() ; 
  int f = -1 ; 
  while(i < path.size() && i<<path2.size()){

    if(path[i]==path2[i]){
      f = path[i];
    }
    else{
      break ;
    }
    i++ ;
    // 1=1 mial store , 2=2 mila store , 5=4 nhi mila break sirf 2 stroeohogya or yeh prefix ke base pe chlta h starting ke bilkul same hongeor aage piche bhi nhi hrohe honge toh koi 0n2 loop nhi ek hi pointer se kaaam hojayega 
  }

cout << endl ; 
cout << " common ancestor : " << f ;

// when matched i++ ; j++ ; the last element mathed is our answer ; 0(N)


}