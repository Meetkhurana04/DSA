void trav(struct node **last, struct node **secondlast) {  // <-- Changed to accept pointers to pointers
        *last = first;
        while ((*last)->link != NULL) {
            *secondlast = *last;
            *last = (*last)->link;
        }
}
void addone(){
        struct node *secondlast,*last,*ptr;
        last=first;
        secondlast=NULL;
  
    while(last!=first || last==NULL){
        trav(&last,&secondlast);
        if(last->info==9){
            last->info=(last->info+1)%10;
            last=secondlast;
            trav(&last,&secondlast); 
        }
        else {
            last->info=last->info+1;
            last=secondlast;
            trav(&last,&secondlast);
        
        }

    if (last==first){
        last->info=(last->info+1)%10;
        if(last->info==9){
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->info=1;
        ptr->link=first;
        first=ptr;
        }
    }     
    else {
        first==last;
    }   
        
    } 
display();   

                
    }