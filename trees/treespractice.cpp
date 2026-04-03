#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data ;
    node* left ;
    node* right ;

    node(int val){
        data = val;
        left = NULL ;
        right = NULL ;
    }
};


void preorder(node* root) {
    if(root == NULL){
        return  ; 
    }
    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);

}

void  postorder(node *root){
    if(root == NULL){
        return ; 
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(node *root){
    if(root == NULL){
        return ; 
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main () { 

node* root = new node(1);
root->left = new node(2);
root->right = new node(3);

root->left->left = new node(4);
root->left->right = new node(5);
cout << "preorder " << endl;
preorder(root);
cout << endl ; 

// preorder kar rhe h // what is preorder root left right 
// 1 2 4 5 4
cout << "postorder " << endl;
postorder(root); // post order mtlb left right root 
cout << endl ; 
cout << "inorder " << endl ;
inorder(root);



return 0 ; 

}

