#include <stdio.h>
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
  node *root = new node(1);

  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->right->left = new node(6);
  root->right->right = new node(7);

  // preorder kya hota h root left right 1 2 4 5 3 6 7
  // postorder left right root 4 5 2 6 7 3 1
  // inorder left root right 4 2 5 1 6 3 7

  //left pe chlete h jah left pe null aaya wha print kardenge 
  stack<node*> st;
  
  node* curr = root ;
  while(true){
    if(curr!=NULL){
      st.push(curr);
      curr=curr->left;
    }
    else{
      if (st.empty() == true) break;
      curr=st.top(); // har baar top se mt khelo kya bta next line me top ht jyae or woh stack khali hojaye toh humpe refereence ho uspe jane ke liye ; dekhskte ho yha mene next line me pop krdiya but chije abhi bhi h tree bch rha h 
      cout << curr->data << endl ;
      st.pop();
      curr=curr->right;
      // do baar baar pop hone ke moke mil rhe h 4 ka left null hua else me aaya 4 pe pkd liya 
    }
  }

}
// 425167

// phel 1 ghuesga fir 2 ghuseaga fir 4 ghusheaga fir 4 curr null hogya null hote hi me top ko yaani 4 ko pkdunga 4 ko print kiya pop kiya toh [1,2] bche and curr = curr-> right hogya curr = 4 tha abhi tk 4-> righ = null'

// dubara null agya fir cur == top = 2 ; print 2 pop kiya [1] bcha curr = curr->right ; kiya 5 pkda 5 is not null stack me push hua 1,5 stack me gye ;now curr = null 5 ko pkda print 5 pop curr = 5-> right null ;

// ab null h curr = 1 hoga 1 print hoga right me jaayegne curr = 3 hojayega left jayenge cur = 6 hojayega left jaayenge null then top ko pkdnege top is 6 print krenge op kreknge cur = 6->right me jaayenge null h fir top pkdenge 3 ko jo ki null nhi h pop krenge 3 ko right me jaayenge 7 


