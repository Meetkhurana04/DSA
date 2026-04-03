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

int main(){ 
stack<node*> st ; 

node* root = new node(1);
root->left = new node(2);
root->right = new node(3);

root->left->left = new node(4);
root->left->right = new node(5);

st.push(root);
if(root == NULL){
    return 0; 
}

    while(!st.empty()){
        node* root = st.top() ; 
        st.pop();
        int x = root->data ;
        cout << x << endl ;
        if(root->right){
            st.push(root->right); 
        } 
        if(root->left){
            st.push(root->left);
        }

    }

    return 0 ; 
}