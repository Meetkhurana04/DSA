#include <iostream>
#include <vector>
#include <map>
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

node *build(vector<int> &preorder, int preStart, int preEnd,
            vector<int> &inorder, int inStart, int inEnd,
            map<int, int> &inMap)
{
  if (preStart > preEnd || inStart > inEnd)
    return NULL;

  node *root = new node(preorder[preStart]);// preorder ke first ko root bnayega 

  int inRoot = inMap[root->data]; // ab mam me woh root dhund ke fetch krunga m value jisse mereko left right ka bta lge
  int numsLeft = inRoot - inStart; // yeh mereko ek range me iljayegi ki yha se leke yha tk left h                   

  root->left = build(preorder,
                     preStart + 1, // preorder ke next wala uska root hoga 
                     preStart + numsLeft,// end left pe hoga
                     inorder,
                     inStart,// instart to h 0 se hi hoga
                     inRoot - 1,// jo b mid h use 1 -1 
                     inMap);

  root->right = build(preorder,
                      preStart + numsLeft + 1, //0+left kapart + 1 se 
                      preEnd, // end tk 
                      inorder, 
                      inRoot + 1, // next wala 
                      inEnd, // same size
                      inMap);

  return root;
}

node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
  map<int, int> inMap;

  for (int i = 0; i < inorder.size(); i++)
  {
    inMap[inorder[i]] = i;
  }

  return build(preorder,
               0,
               preorder.size() - 1,
               inorder,
               0,
               inorder.size() - 1,
               inMap);
}

void preorderPrint(node *root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  preorderPrint(root->left);
  preorderPrint(root->right);
}

void inorderPrint(node *root)
{
  if (root == NULL)
    return;

  inorderPrint(root->left);
  cout << root->data << " ";
  inorderPrint(root->right);
}

int main()
{
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};

  node *root = buildTree(preorder, inorder);

  cout << "Preorder : ";
  preorderPrint(root);

  cout << endl;

  cout << "Inorder : ";
  inorderPrint(root);

  return 0;
}