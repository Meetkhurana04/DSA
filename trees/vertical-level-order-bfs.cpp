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

vector<vector<int>> verticaltraversal(node *root)
{
  map<int, map<int, multiset<int>>> nodes;
  // yeh wala map toh sort or quicker traversal me kaam aayega
  queue<pair<node *, pair<int, int>>> todo;
  // sime actual woh +1 wala logic lgega
  todo.push({root, {0, 0}});
  while (!todo.empty())
  {
    auto p = todo.front();
    todo.pop();
    node *temp = p.first;                        // yeh root ko pdkega mtb tree ke sath khelge a
    int x = p.second.first, y = p.second.second; // yeh kya krega humar jo node h uske x , y pta kar rhe h ;
    nodes[x][y].insert(temp->data);              // isme hum jese bfs me ek  or chij me store krte the wese store kr rhe h
    // oe ia timw hqi hum special map ka use kar rhe h

    if (temp->left)
    {
      todo.push({temp->left, {x - 1, y + 1}});
    }
    if (temp->right)
    {
      todo.push({temp->right, {x + 1, y + 1}});
    }
  }
  // jo todo naam ki h usak use hum bfs ke liye kr rhe h
  // nodes naam ki acutall map h jo sorted key pair ke order me save kar rhe h sab

  vector<vector<int>> ans;
  // yeh humne nya vector banye h jsime hum vertical traversal wise chije store krenge
  for (auto p : nodes)
  { // nodes ko traverse krna h
    // phle wala loop vertical pe chlega
    vector<int> col;
    for (auto q : p.second)
    { // b us vertical ke hisab se saare jo rows h use merge krega
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}

  int main()
{

  stack<node *> st;
  queue<node *> q;
  vector<int> ans;
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
  vector<vector<int>> anss = verticaltraversal(root);

  for (auto col : anss)
  {
    for (auto x : col)
    {
      cout << x << " ";
    }
    cout << endl;
  }
}

