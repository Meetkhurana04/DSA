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

int main()
{
  queue<node *> q;
  stack<vector<int>> st;

  node *root = new node(1);
  root->left = new node(2);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right = new node(3);
  root->right->right = new node(6);

  bool flag = true ; 

  q.push(root);

  while(!q.empty()){
    int size = q.size() ; 
    vector<int> level(size) ; 

    for(int i = 0 ; i < size ; i++){
      node* top = q.front() ; 
      q.pop();

      int index = (flag) ? i : (size - 1 - i);
      // agar tum sahi ho toh i pkdega mtlb starting se lega nhi toh last se 

      // queue me toh same level se jaayega main chij toh yha matter krit h ki lhume use uthake aage kese place krni h wph easy hpga ma age k
      level[index]=top->data ;
      if(top->left!=NULL){
        q.push(top->left);
      }
      if (top->right != NULL)
      {
        q.push(top->right);
      }
    }
    flag = !flag ; 
    st.push(level);

  }
  while (!st.empty())
  {
    auto it = st.top();
    st.pop();
    for (auto i : it)
    {
      cout << i;
    }
    cout << endl;
  }
}
