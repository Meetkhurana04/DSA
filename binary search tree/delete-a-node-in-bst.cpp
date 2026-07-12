#include <iostream>
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

void preorder(node *root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

// Rightmost node of left subtree
node *findLastRight(node *root)
{
  if (root->right == NULL)
    return root;

  return findLastRight(root->right);
}

// Helper function
node *helper(node *root)
{ // agar yhe left h hi nhi toh root->right dedega simple 
  if (root->left == NULL)
    return root->right; // isme kya hoga ki root ko direct hum right se connect krdenge 

  if (root->right == NULL)
    return root->left;

  node *rightChild = root->right; // jo root  ka right h voh hume last right mtlb chote me jodna h findlastright(root->left);
  node *lastRight = findLastRight(root->left);
   /// mene smalest dhundliya last right me jaake  and fir use joda jo root ka right rhgya 
  lastRight->right = rightChild;

  return root->left;
}

// Delete node
node *deletenode(node *root, int key)
{
  if (root == NULL)
    return NULL;

  if (root->data == key)
    return helper(root);

  node *dummy = root;

  while (root != NULL) // b hum search krne niklenge 
  {
    if (key < root->data) // kya key choti h toh hum left side se jaayenge 
    {
      if (root->left != NULL && root->left->data == key)
      {// kya root left exist krta h or woh key ke equal h nhi h toh root->left hote rho h toh use helper me bhejo
        root->left = helper(root->left);
        break;
      }
      else
      {
        root = root->left;
      }
    }
    else
    {
      if (root->right != NULL && root->right->data == key)
      { // yeh right me dhundega or dekhag if key ke equal h and root= root->right ; 
        root->right = helper(root->right);
        break;
      }
      else
      {
        root = root->right;
      }
    }
  }

  return dummy;
}

int main()
{
  // BST
  node *root = new node(5);

  root->left = new node(3);
  root->left->left = new node(2);
  root->left->right = new node(4);

  root->right = new node(7);
  root->right->left = new node(6);
  root->right->right = new node(8);

  cout << "Before Deletion: ";
  preorder(root);

  int key = 4;
  root = deletenode(root, key);

  cout << "\nAfter Deletion: ";
  preorder(root);

  return 0;
}