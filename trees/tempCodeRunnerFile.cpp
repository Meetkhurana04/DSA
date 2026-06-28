int preorder(node *p , node* q){
  if(p==NULL || q==NULL){
    return (p==q); // toh yeh dono case hindle krdega either p or q dono case handle hojayenge 
  }
  return (p->data == q->data) && preorder(p->left, q->left) && preorder(p->right, q->right) ;
}