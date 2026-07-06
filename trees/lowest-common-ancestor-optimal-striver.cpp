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

node *LCA(node *root, int key1, int key2)
{
  // Base case
  if (root == NULL)
    return NULL;

  // Agar current node hi kisi key ke equal hai
  if (root->data == key1 || root->data == key2)
    return root;

  // Left aur right subtree me search karo
  node *left = LCA(root->left, key1, key2);
  node *right = LCA(root->right, key1, key2);

  // Sirf right subtree me mila
  if (left == NULL)
    return right;

  // Sirf left subtree me mila
  else if (right == NULL)
    return left;

  // Dono taraf mila -> current node LCA hai
  else
    return root;
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

  int k1 = 4;
  int k2 = 7;

  node *ans = LCA(root, k1, k2);

  if (ans != NULL)
    cout << "Lowest Common Ancestor : " << ans->data << endl;
  else
    cout << "Key not found!" << endl;

  return 0;
}