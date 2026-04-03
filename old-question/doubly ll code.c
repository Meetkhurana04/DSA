//double link
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    struct node *lpt;
    int info;
    struct node *rpt;
};
struct node *first;

void create();
void display();


int main(){
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
        insert_beg();
    }

    else if(choice==2){
        insert_btw();
    }

  else if(choice==3){
        insert_last();
    }

   else if(choice==4){
        delete_beg();
    }

   else if(choice==5){
        delete_last();
    }

    else if(choice==6){
        delete_btw();
    }

    else{
        printf("hatt pagal");
    }
    }
    }
    

}

// creation of doubly link list
void create(){
    struct node *ptr,*cpt;
    char ch ;
    int data;
    ptr =(struct node*)malloc(sizeof(struct node) );
    printf("enter node");
    scanf("%d",&ptr->info);
    ptr->rpt=ptr->lpt=NULL;// dono ko null krdiya gya ki age khela jaske 
    first = ptr;
do{
    cpt=(struct node*)malloc(sizeof(struct node));
    printf("enter new node");
    scanf("%d",&cpt->info);
    ptr->rpt=cpt;
    cpt->lpt=ptr;
    ptr=cpt;
     printf("Do you want to create more Nodes? Press 'Y' for yes and 'N' for no:");
    fflush(stdin);
    scanf("%c",&ch);
}
while(ch == 'y');
    ptr->rpt=NULL;
}
void display(){
    struct node *ptr=first;
    while(ptr!=NULL){
        printf("%d",ptr->info);
        ptr=ptr->rpt;
    }
}

void insert_beg(){
    struct node *cpt,*ptr;
    ptr= (struct node*)(malloc(sizeof(struct node)));
    printf("enter indo");
    scanf("%d",&ptr->info);
    first->rpt=ptr;
    ptr->lpt=first;
    first=ptr;
    display();

   
    
}

void insert_last(){
    struct node *ptr,*cpt;
    ptr=first;
    while(ptr!=NULL){
        ptr=ptr->rpt;
    }
   cpt=(struct node*)(malloc(sizeof(struct node )));
   printf("entro inof");
   scanf("%d",&cpt->info);
  ptr->rpt = first;
first->lpt = ptr;
first = ptr;

   display();


}

void insert_btw(){
 struct node *ptr,*cpt;
 int data;
 ptr=(struct node*)(malloc(sizeof(struct node)));
 printf("enter info");
 scanf("%d",&ptr->info);
 printf("enter place jha ako add krnah ");
 scanf("%d",&data);
 cpt=first;
 while(cpt->info!=data){
    cpt=cpt->rpt;

 }
 ptr->rpt=cpt->rpt;
 ptr->rpt->lpt=ptr;
 ptr->lpt=cpt;

 cpt->rpt=ptr;
 display();
 
}

void delete_beg(){
    struct node*cpt,*ptr;
    cpt=first;
    first=first->rpt;
    cpt->rpt=NULL;
    first->lpt=NULL;
    free(cpt);
    display();
}

void delete_last(){
    struct node*cpt,*ptr;
    ptr=first;
    while(ptr->rpt!=NULL){
        cpt=ptr;
        ptr=ptr->rpt;



    }
    cpt->rpt=NULL;
   
    free(ptr);
    
}
void delete_btw(){
    struct node *ptr = first;

    int data;
    printf("enter node in which you want to delete");
    scanf("%d",&data);
    while(ptr->info!=data){
       
       ptr=ptr->rpt;

    }
    ptr->lpt=ptr->rpt;
    ptr->rpt->lpt=ptr->lpt;
    free(ptr);
    display();
}

