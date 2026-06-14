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

node* root = new node(1);
root->left = new node(2);
root->right = new node(3);

root->left->left = new node(4);
root->left->right = new node(5);
// iske liye ek quueue lenge or ek vector ke andar vector lenge 

queue<node*> q ; 
vector<vector<int>> ans;

q.push(root);

while(!q.empty()){
    int size = q.size() ; 
    /// phle root ghusana h use pop kre and bhai behan daalo uske 
    vector<int> level ; 

    for(int i = 0 ; i<size ; i++){
        node* root = q.front();
        q.pop();
        // front pkd liya 
        
        if(root->left!=NULL){
            q.push(root->left);
        }
        if(root->right!=NULL){
            q.push(root->right);
        }
        level.push_back(root->data);
    }

    ans.push_back(level);

}

for(auto it : ans){
    for(auto i : it){
        cout << i << " ";
    }
    cout << endl ; 
}

return 0 ; 

}