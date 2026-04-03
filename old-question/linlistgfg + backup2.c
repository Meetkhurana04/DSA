#include<stdio.h>
#include<conio.h>
#include<stdlib.h>// maloc ke liye necesary h ji
// remove link list element
/*Q 4 h yhe remove link list  elmeent isme kya krna h ki link list element ke agar koi 
same element hai like if 6 do baa rarha h dono deltet krek printkrena h 
203. Remove Linked List Elements removellelement();
q5 delete alternate from link list like even number
q6 012 ko sort krke likhna h ;
q7 sortedlist insert isme kya kiya jaata h ki ek sorted list hoti h usme correct position pe dalna h function use sortedlistinsert()
q8 split link list into two halves 
q9 merge sort on link list;
 */
struct node{
    int info;
    struct node *link;          
};
struct node* first;


void create();
void display();
void insert_at_beg();
void insert_last();
void insert_btw();
void delete_beg();
void delete_end();
void delete_btw();
void sum();
void middle();
void nodeatgivenindex();
void removellelement();
void deletealternate();
void sortedlistinsert();
void sort012();
void display012(int count1,int count2,int count3);
void splitlinklist();
void pairwiseswap();

void main(){

    int choice;

    create();
    display();

    printf("\nMenu:\n Enter 0 for ending the program\nEnter 1 for inserting another node at the beginning and choice 2 for insert at last and choice 3 to insert at between insert 4 for delete at beginning insert 5 for delete at begining insert 6 for delete at btw insert 7 for sum of all linked list element insert 8 for finddling middle element in a linkllist press 11 for delete at alternate places \n");

    for(;;){
  printf("Enter your choice:");
    scanf("%d",&choice);

    if(choice==0){
         break;
    }

    else if(choice==1){
        insert_at_beg();
    }

    else if(choice==2){
        insert_last();
    }

    else if(choice==3){
        insert_btw();
    }

   else if(choice==4){
        delete_beg();
    }

   else if(choice==5){
        delete_end();
    }

    else if(choice==6){
        delete_btw();
    }
    else if(choice==7){
        sum();
    }
    else if(choice==8){
        middle();
    }
    else if(choice==9){
        nodeatgivenindex();
    }
    else if(choice==10){
        removellelement();

    }
    else if(choice==11){
        deletealternate();
    }
    else if(choice==12){
        sort012();
    }
    else if(choice==13){
        sortedlistinsert();
    }
    else if(choice==14){
         splitlinklist();
    }
    // else if(choice==15){
    //     // mergesort();
    // }
    else if(choice==16){
        pairwiseswap();
    }

    else{
        printf("hatt pagal");
    }
    }
    }


}

//Creation of a Single Linked List
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
    scanf("%c",&ch);

    // upr jayega cpt bnega fir ptr ka lin( 2nd wale ka) cpt 3rd wale ko dediyaa
    }while(ch=='y');

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
}

//Insertion of a node at the beginning of a linked list
void insert_at_beg(){
    struct node *ptr,*cpt;

    ptr=(struct node*)malloc(sizeof(struct node));

    printf("Enter info for new node:");
    scanf("%d",&ptr->info);

    ptr->link=first;// jo nya ptr bna h uske link ko first ka adress dedidiya mtlb 100
    first=ptr;//ab first ko jo nya bna h  uska adress dediya
    

    display();
}
void insert_last(){
    struct node *ptr,*cpt;
    
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter at last new info");
    scanf("%d",&ptr->info);
    ptr->link=NULL;
    cpt=first;
    while(cpt->link!=NULL){
      cpt=cpt->link;
      
    }
    cpt->link=ptr;
    display();
    
}
void insert_btw(){
     int data ;
     struct node *cpt,*ptr;
     printf("tell at which place you need to ammend");
     scanf("%d",&data);
     ptr=(struct node*)malloc(sizeof(struct node));
     printf("enter at between new info :");
     scanf("%d",&ptr->info);
     cpt=first;
     while(cpt->info!=data){
            cpt=cpt->link;
         }
         ptr->link=cpt->link;
         cpt->link=ptr;
         display();
     
     
}
void delete_beg(){
   
   struct node *ptr;
   ptr=first;
   first=first->link;
   free(ptr);
   printf("nodes after deletion");
   display();
}
void delete_end(){
    struct node *ptr,*cpt;
    ptr=first;
    while(ptr->link!=NULL){
        cpt=ptr;
        ptr=ptr->link;// i ++ wali hogi

    }   
    cpt->link=NULL;
    free(ptr);
    printf("nodes after deletion");
    display();

}
void delete_btw(){
    struct node *ptr,*cpt;
    int data;
    printf("where you want to delete");
    scanf("%d",&data);
    ptr=first;
    while(ptr->info!=data){
        cpt=ptr;
        ptr=ptr->link;
    }
    cpt->link=ptr->link;
    free(ptr);

    printf("nodes after deletion:\n");
    display();
}
  
void sum(){
    int sum = 0;
    struct node *cpt,*ptr;
    ptr=first;
    while(ptr!=NULL){
        sum=sum+ptr->info;
        ptr=ptr->link;



    }
    printf("sum is :");
    printf("%d",sum);
}
void middle(){
    struct node *ptr, *cpt;
    int count=0;
    
    ptr=first;

    while(ptr!=NULL){
        count++;
        ptr=ptr->link;
    }
        int x;
    if(count%2==0){
        x=count/2  + 1;
    }
    else{
        x=count/2  + 1;

    }
    ptr=first;
      ptr = first; // Reset ptr to the head of the list
    for (int i = 1; i < x; i++) {
        ptr = ptr->link;
    }
    printf("%d\n",ptr->info);
    
}
void nodeatgivenindex(){
    int x;
    struct node *ptr,*cpt;
    ptr=first;
    printf("enter value");
    scanf("%d",&x);
    while(x>1 && ptr!=NULL){
        ptr=ptr->link;
        x=x-1;

    }
    
    printf("%d/n",ptr->info);
     
}
void removellelement(){
    struct node *ptr,*cpt,*prev,*head;
    head=first;
    int x;
    printf("konsa element delte krna h tell elment value not index\n");
    scanf("%d",&x);
    // while(ptr!=NULL){
    //     prev=ptr;
    //     ptr=ptr->link;
    //     if(ptr->info==x){
               //cpt=ptr;
            //    free(cpt)
            // prev->link=
            // kuch glt sa hoga ki ek prev ko pkdega ek uski vale rkhega or ek agge wale ko dekhega


    //     }

    // }
     // ye jo method tha 3 pointer ka tha kind of lon kyuki merko dr tha ptr ko hi free krdunga toh ptr aage kese bdhega
//easy two pointer method
 //phle base case krenge jo show krega ki if head ko hi ignore krna ho toh kya kroge
// teen pointer toh isme bhi liye h but better hh 
 while(head!= NULL && head->info==x){
    struct node *temp;
    head=head->link;
    free(temp);


 }

 if (head==NULL){
    return NULL;
 }
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// struct ListNode* removeElements(struct ListNode* head, int val) {
//     // Handle the case where the head needs to be removed
//     while (head != NULL && head->val == val) {
//         struct ListNode* temp = head;
//         head = head->next;
//         free(temp);
//     }

//     // If the list is empty after removing head elements
//     if (head == NULL) {
//         return NULL;
//     }

//     // Use two pointers to traverse the list and remove elements
//     struct ListNode* current = head;
//     struct ListNode* prev = NULL;

//     while (current != NULL) {
//         if (current->val == val) {
//             prev->next = current->next;
//             free(current);
//             current = prev->next;
//         } else {
//             prev = current;
//             current = current->next;
//         }
//     }

//     return head;
// }
void deletealternate(){
    struct node *ptr,*temp;
    ptr=first;
    while(ptr->link!=NULL){
      //ptr first ko point kr rha h
      temp=ptr->link;// temp ne delte hone wala pkd liya
      ptr->link=temp->link; // bypass krdiya jump 
      free(temp);
      ptr=ptr->link;
      // ab nikal jayega toh direct lin h aage aram se bdhao      
        
    }
    display();
}
void sortedlistinsert(){
    struct node *ptr,*cpt;
    struct node *mpt=(struct node *)malloc(sizeof(struct node));
    int x;
printf("enter node");
scanf("%d",&x);
//30
//2040 20<40
ptr=first;
 if (first == NULL || first->info >= x) {
        mpt->link = first;
        first = mpt;
}
else{
while(ptr != NULL && ptr->info < x){
    cpt=ptr;
    ptr=ptr->link;
}
cpt->link=mpt;
mpt->link=ptr;
mpt->info=x;
}
display();

}
void sort012(){
    struct node *ptr,*cpt;
    int count1=0;
    int count2=0;
    int count3=0;
    ptr=first;
    while(ptr!=NULL){
        if(ptr->info==1){
            count1++;
        }
        else if(ptr->info==2){
            count2++;
        }
        else if(ptr->info==0){
            count3++;

        }
        ptr=ptr->link;

       
        
    }
     printf(" 1 :%d 2 :%d 0:  %d",count1, count2 ,count3);
     display012(count1,count2,count3);

}
void display012(int count1,int count2,int count3){
    struct node *cpt;
    //  cpt=(struct node*) malloc(sizeof(struct node));
     cpt=first;
     while(count3>0){
        cpt->info=0;
        cpt=cpt->link;
        count3--;
     }
     while(count1>0){
        cpt->info=1;
        count1--;
        cpt=cpt->link;
     }
      while(count2>0){
        cpt->info=0;
        count2--;
        cpt=cpt->link;
     }
     
     display();
     


}
void splitlinklist(){
    // struct node *ptr,*cpt;
    struct node *fast,*slow,*prev;
    fast=first;
    slow=first;

    while(fast!=NULL && fast->link!=NULL){

        fast=fast->link->link;// 2x speed
        prev=slow;
        slow=slow->link;

    }
    // struct node *temp;
    prev->link=NULL;
    displaysplit(first,slow);
}
void displaysplit(struct node *firsthalf,struct node *secondhalf){
    struct node *ptr;
    printf("fisrt half : ");
    ptr=firsthalf;//firsthalf ke end me toh humne automatically null kr rkha h toh whii ruk jayega
    while(ptr!=NULL){
        printf("[%d] ",ptr->info);
        ptr=ptr->link;

    }
    printf("\n");
    printf("second half: ");
    ptr=secondhalf;
    while(ptr!=NULL){
        printf("[%d] ",ptr->info);
        ptr=ptr->link;
        

        
    }
}

void pairwiseswap(){
    //16
    struct node*ptr,*cpt,*temp;
    ptr=first;
    if(ptr==NULL){
        return ptr;
    }
    first=ptr->link;
    //phli ko khud swap krna pda
    while(ptr!=NULL && ptr->link!=NULL){
        cpt=ptr;
        ptr=ptr->link;
        temp=ptr->link;
        ptr->link=cpt;
        cpt->link = (temp != NULL && temp->link != NULL) ? temp->link : temp;
        ptr=temp;

    }
    display();
void reversebothparts();

}
// void mergesort(){
//  struct node *ptr,*cpt;
//  // middle nikalna h 
//  // merge sort ka likhna h 
//  // merge ka likhna  
//    void mid(struct node *head){
//     struct node *fast, *slow;
//     if(head==NULL){
//         return head;
//     }
//     fast=head;
//     slow=head;
//     while(fast!=NULL && fast->link!=NULL){
//         fast=fast->link->link;
//         slow=slow->link;

//     }
//     return slow;

//  }
//  void ms(struct node *head){
//     if (head==NULL || head->next==NULL){
//         return head;
//     }
//     node *middle = mid(head)
//     node *nexttomiddle = middle->next;
//     // do bart hogye dono ke starting ke pointer milegye

//     middle->next=NULL;
//     node *left=ms(head);
//     node *right=ms(nexttomiddle)
//     node *sortedlist=mergetwosortedlist(left,right)
//     return sortelist ;
//  }
//  void mergetwosortedlist()
// }