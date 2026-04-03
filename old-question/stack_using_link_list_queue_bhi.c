 //implementing stack using link list 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//Included stdlib.h for the malloc() and free() functions

struct node{
    int info;
    struct node *link;          
};
struct node* first;

void create();
void display();
void push();
void pop();


void create(){
    struct node *ptr,*cpt;
    char ch;

    ptr=(struct node*)malloc(sizeof(struct node));

    printf("Enter info:");
    scanf("%d",&ptr->info);
    ptr->link=NULL;
    first=ptr;

    // printf("Do you want to create more Nodes? Press 'Y' for yes and 'N' for no:");
    // char ch;
    // scanf("%d",&ch);

    do{
    
    cpt= (struct node*)malloc(sizeof(struct node));
    printf("Enter info:");
    scanf("%d",&cpt->info);

    ptr->link=cpt;// jo ptr null tha use jod diyaa
    ptr=cpt;//then ptr ko cpt pe point krwaya mtlbnow ptr point at 2nd and cpt bhi 2nd;
    
    printf("Do you want to create more Nodes? Press 'Y' for yes and 'N' for no:");
    fflush(stdin);
    scanf(" %c",&ch);

    // upr jayega cpt bnega fir ptr ka lin( 2nd wale ka) cpt 3rd wale ko dediyaa
    }while (ch == 'Y' || ch == 'y');

    ptr->link=NULL;


}

//Display Function for the created linked list
void display(){
    struct node*ptr;

    ptr=first;// jis ptr ko chlaoge use firs tpe toh rkho kkoi

    printf("Your Info: \n");

    while(ptr!=NULL){
        printf("->[%d] ",ptr->info);
        ptr=ptr->link;

    }
    printf("\n");

    //push bhi aage se pop bhi aage se
}
void push(){
    struct node *ptr,*cpt;

    ptr=(struct node*)malloc(sizeof(struct node));

    printf("Enter info for new node:");
    scanf("%d",&ptr->info);

    ptr->link=first;// jo nya ptr bna h uske link ko first ka adress dedidiya mtlb 100
    first=ptr;//ab first ko jo nya bna h  uska adress dediya
    //jo bhi push hoga whi first hojaye top 

    display();
}

void pop(){
   
   struct node *ptr;

   
   ptr=first;
   if (ptr==NULL){
    printf("stack underflow");
   }
   first=first->link;
   free(ptr);
   printf("nodes after deletion");
   display();
}
int main(){
      int choice;

    create();
    display();
    printf("Enter 1 for push in the stack ,2 for pop in the stack , 3 for display in the stack");
    for(;;){
  printf("Enter your choice:");
    scanf("%d",&choice);

    if(choice==0){
         break;
    }

    else{
    if(choice==1){
        push();
    }

    else if(choice==2){
        pop();
    }

    else if(choice==3){
        display();
    }}}
}




// #include<stdio.h>
// #include<conio.h>
// #include<stdlib.h>//Included stdlib.h for the malloc() and free() functions

// struct node{
//     int info;
//     struct node *link;
// };
// struct node *front, *rear;

// void create();
// void display();
// void enqueue();
// void dequeue();

// void create(){
//     front = rear = NULL;
// }

// void display(){
//     struct node*ptr;
//     ptr=front;

//     if(front == NULL) {
//         printf("Queue is empty.\n");
//         return;
//     }

//     printf("Queue: \n");
//     while(ptr != NULL){
//         printf("->[%d] ", ptr->info);
//         ptr = ptr->link;
//     }
//     printf("\n");
// }

// void enqueue(){
//     struct node *ptr;

//     ptr = (struct node*)malloc(sizeof(struct node));

//     printf("Enter info for new node to enqueue:");
//     scanf("%d", &ptr->info);

//     ptr->link = NULL;

//     if(front == NULL) {
//         front = ptr; // If the queue is empty, both front and rear will point to the new node.
//         rear = ptr;
//     } else {
//         rear->link = ptr; // Link the new node to the end of the queue.
//         rear = ptr; // Move rear to the newly added node.
//     }

//     display();
// }

// void dequeue(){
//     struct node *ptr;

//     if(front == NULL) {
//         printf("Queue underflow\n");
//         return;
//     }

//     ptr = front;
//     front = front->link; // Move front to the next node.

//     printf("Dequeued element: %d\n", ptr->info);
//     free(ptr);

//     if(front == NULL) {
//         rear = NULL; // If the queue becomes empty, set rear to NULL.
//     }

//     printf("Queue after dequeue:\n");
//     display();
// }

// int main(){
//     int choice;

//     create();
    
//     printf("Enter 1 for Enqueue in the Queue, 2 for Dequeue in the Queue, 3 for Display in the Queue, 0 to Exit\n");

//     for(;;){
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         if(choice == 0){
//             break;
//         } else {
//             if(choice == 1){
//                 enqueue();
//             } else if(choice == 2){
//                 dequeue();
//             } else if(choice == 3){
//                 display();
//             }
//         }
//     }

//     return 0;
// }
