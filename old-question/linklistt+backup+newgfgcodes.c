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
void prewrittenll();
void addone();
void addoneusingrev();

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
    else if(choice==17){
        reverse();
    }
    else if(choice == 18){
        reversebothparts();
    }
    else if(choice == 19){
        addone();
    }
    else if(choice == 20){
        addoneusingrev();
    }

    else{
        printf("hatt pagal");
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



}

void reverse() {
    // struct node *prev, *curr, *next;
    // prev = first;
    // curr = first->link;
    // next = curr->link;
    
    // while (curr != NULL) {
    //     curr->link = prev;
    //     prev = curr;
    //     curr = next;
        
    //     if (next != NULL) {  // Ensure next is not NULL before accessing next->link
    //         next = next->link;
    //     }
    // }
    
    // first = prev;  // Update first to point to the new head (last node processed)

    // display();
    // empty list, single-node list) 
    // this is my  code which was working well but not handeling edge cases 
    struct node *prev,*current;
    if(first!=NULL){
        prev= first;
        current=first->link;
        first=first->link;
        prev->link=NULL;// ye null kyu kiya kyuki iske ppiche kuch point krne ko h hi nhi toh yeh null hi rhega
        // vese bhi jb ulta hoga yeh last element bnega jis se last element ka link toh null hi hota h na 

    // for 1 block ke liye yyeh hogaa jese LL me code 1 hi block h usme yeh
    // 1 element kese check krega upr first !+null se check krega agar first = null hai mtlb iske aage koi element nhi h or 
    //yhi proceed hoga 

    //and jo below code h vo tbhi chlega jb first != null h or tb tk chlega ki first != null nhi hojata
    }
    while(first!=NULL){
        // for block 2,3,4,n yeh chlega 
        first=first->link;
        current->link=prev;//current wale ka link prev ko dediya
        prev=current; //prev ko aage bdhaya
        current=first;
    }
    //last me first aage chla jayega toh use piche rok lena h 
    //first null na ho jaye kyuki first sbse jldi bhagata h
    first=prev;
    display();

}


void reversebothparts() {
    struct node *ptr = first;
    int count = 1;
    int x;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    while(ptr->link != NULL) {
        count++;
        ptr = ptr->link;
    }

    struct node *prev = NULL, *current = NULL, *temp = NULL;
    temp = first;

    // Reverse the first x nodes
    while(x > 0 && first != NULL) {
        prev = NULL;  // Reset prev for each iteration
        current = first;  // Start with the current first node

        // Reverse the first x nodes one by one
        while(x > 0 && current != NULL) {
            first = current->link;  // Move first forward
            current->link = prev;  // Reverse the link
            prev = current;  // Move prev forward
            current = first;  // Move current forward
            x--;
        }

        // After the first part is reversed, prev is the new head
        first = prev;
        temp->link = current;  // Link the end of the first part to the start of the second part

        // Print the state after reversing the first part
        printf("After reversing the first part:\n");
        display();
    }

    // Reverse the remaining nodes
    prev = NULL;  // Reset prev
    struct node *remaining = current;  // Start with the first node of the second part

    while(remaining != NULL) {
        struct node *next = remaining->link;
        remaining->link = prev;
        prev = remaining;
        remaining = next;
    }

    temp->link = prev;  // Link the end of the first part to the reversed second part

    // Final print after the complete reversal
    printf("Final reversed list:\n");
    display();
}
void trav(struct node **last, struct node **secondlast) {
    //if i use only *last,*secodnlast toh isme yeh hojata ki copieski value change 
    // ??hpgi but hume dono ki avlaue chahiye

    *last = first;
    *secondlast = NULL;  // Initialize secondlast to NULL to handle single-node lists

    while ((*last)->link != NULL) {
        *secondlast = *last;
        *last = (*last)->link;
    }
}

void addone() {
    struct node *secondlast, *last, *ptr;
    last = first;
    secondlast = NULL;
  
    while (last != NULL) {  // Changed loop condition to correctly traverse through the list
        trav(&last, &secondlast);//yha pe end nhi use kr rha tha which is mandatory

        
        if (last->info == 9) {
            last->info = (last->info + 1) % 10;
            last = secondlast;  // Move to the previous node
            // traverse ho toh jayega jb yeh chij ext hogi toh dikkt nhi leni 
            //cause kuch bhi aisa nhi h jo overlaaap kr rha sb alag kaam kr rhe h iske baad loop exit hi hoga except first;

            // No need to traverse again, as last and secondlast are already updated
        } else {
            last->info = last->info + 1;
            // iwas not using break here 
            break;  // Break the loop as no further carry is needed
            // break is necessary one toh sirf last me add krna h naaki saari jgh

        }


        // Check if we've reached the start of the list and still have a carry
        if (last == NULL || last == first) {
            
              // Added a NULL check to handle cases where we reach the beginning
            if (first->info == 0) {  // If the first node's info is 0 after increment
                ptr = (struct node*)malloc(sizeof(struct node));
                ptr->info = 1;
                ptr->link = first;
                first = ptr;
            }
            break;
               //break krdo no else needed; 
              // Exit loop once we handle the carry at the first node
        }
    }
 // ek or asan trika hota isko reveerse krdo , then kro , then fir reverse krdena
    display();   
}
void addoneusingrev(){
    struct node *cpt,*ptr;
     reverse();
    ptr=first;
while(ptr!=NULL){
    if(ptr->info==9){
        ptr->info=0;
        ptr=ptr->link;

    }
    else{
        ptr->info=ptr->info+1;
        break;

    }
}
    if (ptr == NULL){
        struct node *last;
       cpt = (struct node*)malloc(sizeof(struct node));
        cpt->info = 1;  // New node with value 1
        cpt->link = NULL;  // New node will be the new end of the list
        
        // Find the last node in the reversed list
        last = first;
        while (last->link != NULL) {
            last = last->link;
        }
        last->link = cpt;

    }


 reverse();
}

//dry run of my void add one;
/*mere phle wale code ki kya kyh glti thi ;
void trav andar rkh rha tha jo c++ me allowed nhi h*

dry run lets take 9999
jb tk last null nhi h 
last tk le chlte h last points to 4th 9 , secondlast points to 3th 9
if lat _>info 9 jo ki h 
toh +1 honjayega jo ki hojayega 0
last=second last p ekrdenge thats means yeh hogya ki 3rd 9 pe
ab kya dubar a9 h ?
hn
toh same +1 ho jayeg 0 hojayeg a
now last points to 2nd 9
firse 9 toh +1 0 hogya 
last will point to 1st 9
firse 9 toh 0 now last willl point to null
ab yaha toh last null h ya first toh 
last null hh yhe proceed hogya 
humne first index ko first se pkada rkha h 
agar wo 0 h toh hum aage ek one jod denge simple
agar first ka info 0 nhi h toh bhi break krdo 
lests dry run 
3,9,4,9,9

while(last!=NULL)
last null nhi h kyu ki wo first ko pooint ko point kr rhe ah 
toh it will proceed then call trav()
call krne pe last now will point to 5th 9 second last will point to 4th 9 
isme kya hoga ki 
if last ->inof = 9 jo ki h toh lastke info me +1 hoyga 0 aayega
last =seconldast this means ;ast 4th 9 ko point krega ;
now again last 9 hi h toh +1 ko hoke 0 hoajyega jisse ki 
then last 3rd index 4 ko point krega ;
tehn wo +1 hojayega or break hojayega loop se bhar aagya 
that measn yeh ab 39500

another dry run for no carry needed ;
isme kya hoga 1,2,3
while*last!=NULL
isme kya hoga ki last = frist h wo procced krega
lastt==9 nhi h jiski wjh se last else pe jaayega or info+1 hoke break hojayeg
124 is the answer 

now kya hoga ki
single output = 9
ke sath krete h while loop me jaayega or then 9 h toh +1 hojayega 
hogya last will procedd t last=secondlast that means last abhi null pe 

checks if last==NULL yeh toh 
first->info = 0 h hn h 
toh yeh kya krega ki ek 1 aage jod dega then 
loop proceed hi nhi hoga ki last 9 h oth it will end ;
*/


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