#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *first;
void create();
void display();
void insertfirst();
void insertend();
void insertbtw();
void create(){
    struct node *ptr,*cpt;
    char ch;
    ptr = (struct node*)malloc(sizeof(struct node));

    printf("enter info ");
    scanf("%d",&ptr->info);
    first = ptr;
    ptr->next=NULL;
    ptr->prev=NULL;
    do{
    cpt = (struct node*)malloc(sizeof(struct node));
    printf("enter info ");
    scanf("%d",&cpt->info);
    cpt->prev=ptr;
    ptr->next=cpt;
    
    ptr=cpt;
    
    printf("Do you want to create more Nodes? Press 'Y' for yes and 'N' for no:");
    fflush(stdin);
    scanf("%c",&ch);

      
        }
        while (ch == 'Y' || ch == 'y');
        
        ptr->next=NULL;
}
void display(){
    struct node *ptr=first;
    while(ptr!=NULL){
        printf("->[%d]",ptr->info);
        
        ptr=ptr->next;

    }
    printf("\n");
    
    
}
void main(){
    int choice;
    create();
    display();
    
    printf("Menu:\n Enter 0 for ending the program\nEnter 1 for inserting another node at the beginning and choice 2 for insert at last and choice 3 to insert at between insert 4 for delete at beginning insert 5 for delete at begining insert 6 for delete at btw\n");

    for(;;){
  printf("Enter your choice:");
    scanf("%d",&choice);

    if(choice==0){
         break;
    }

    else{
    if(choice==1){
        insertfirst();
    }

    else if(choice==2){
        insertend();
    }

//     else if(choice==3){
//         insert_btw();
//     }

//    else if(choice==4){
//         delete_beg();
//     }

//    else if(choice==5){
//         delete_end();
//     }

//     else if(choice==6){
//         delete_btw();
//     }

    else{
        printf("hatt pagal");
    }
    }
    }
    
    }




void insertfirst(){
    struct node *ptr=(struct node*) malloc (sizeof(struct node));
    struct node *temp=first;
    printf("enter info to insert at first");
    scanf("%d",&ptr->info);
    ptr->next=first;//important
    first=ptr;
    first->prev=NULL;
    display();

}
void insertend(){
    struct node *cpt;
    struct node *ptr=(struct node*) malloc (sizeof(struct node));
    printf("enter to insert at end");
    scanf("%d",&ptr->info);
    while(cpt->next!=NULL){
        
        cpt=cpt->next;
    }
    cpt->next=ptr;
    ptr->prev=cpt;
    ptr->next=NULL;

    display();
    
    
}

void insertbtw(){
    int data;
    printf("enter in which way you want to ammend");
    scanf("%d",&data);

    struct node *ptr,*cpt;
    struct node* new=(struct node *)malloc(sizeof(struct node ));

    printf("enter new node");
    
    scanf("%d",&new->info);
    ptr=first;
    while(ptr->info!=data){
        cpt=ptr;

        ptr=ptr->next;
 
    }
    cpt->next=new;
    new->prev=cpt;
    ptr->prev=new;

}
