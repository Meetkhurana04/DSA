#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int info;// int info krte h naki struct info
    struct node *rpt;
    struct node *lpt;
};
struct node *first; // first can acces all above vALUE



void create();
void display();


void create(){
    struct node *ptr,*cpt;
    char ch;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("enter info");
    scanf("%d",&ptr->info);
    first = ptr;
    ptr->lpt=ptr->rpt=NULL;
    // first node bnadiya 
    //according to me ek hi baar bnalete but aise shi rhega ki phle ek bnadiya or use first assign krdiya
    // ye do wala baar baaar repaeat hoga na ki upr se 
    
    do{
      cpt = (struct node*)malloc(sizeof(struct node));
      printf("enter info");
      scanf("%d",&cpt->info);
      ptr->rpt=cpt;
      // ptr ke ko adress de rhe h na ki cpt ko
      // ptr ke rpt ko cpt ka adress dediya jo ki nya h;
      
      cpt->lpt=ptr;
      // cpt le lpt ko prev adress dediya jo ki purana h;

      ptr=cpt;  
      // ptr ko cpt dediya jisse ptr aage bdh gya 
      // takes the place of ptr
      // and now a new cpt will formed
      printf("Do you want to create more Nodes? Press 'Y' for yes and 'N' for no:");
      fflush(stdin);
      scanf("%c",&ch);

      
        }
        while(ch=='y');
        ptr->rpt=NULL;

}
void display(){
         struct node *ptr =first;
         printf("ypur info\n");
         while(ptr!=NULL){
            printf("%d\n",ptr->info);

            ptr=ptr->rpt;

         }

}
void insert_beg();// dono me void ayega declare me bhi intialisation me bhi;
void insert_beg(){
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("enter new info");
    scanf("%d",&ptr->info);
    ptr->lpt=NULL;
    ptr->rpt=first;// rpt hi first dedidiya 
    first->lpt=ptr;// jo ki null tha ptr ka lpt humne use uske piche wale ki vlaue dediiii
    first=ptr;//ab nye wale ptr ko first bnadiay
    display();
}
void insert_end();
void insert_end(){
    struct node *ptr,*cpt;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("enter new info");
    scanf("%d",&ptr->info);
    // ptr hold the value jo dlegi last me ptr is the desired node
    cpt=first;//cpt ab first ko point krega ,compiler ko pta h first first ko hi hold krerga 

    //now end tk transverse
    while(cpt->rpt!=NULL){
    cpt=cpt->rpt;// ise age chl lenge;
    

    }
    ///last me phuch gya;
    ptr->lpt=cpt;
    ptr->rpt=NULL;
    display();
    
    }     
                                        
   void insert_btw(); 
   void  insert_btw(){
        int data;
        struct node *ptr,*cpt;
        ptr = (struct node*)malloc(sizeof(struct node));
        printf("enter info");
        scanf("%d",&ptr->info);
        printf("enter in which you want to ammend");
        scanf("%d",&data);
        // cpt ko dirst krdo kyuki usse hi transverse horha h;
        cpt=first;
        while(cpt->info!=data){
            cpt=cpt->rpt;/// condition jisse age bdhega 
        }
        //jo khali h vo phle bharenge
        ptr->rpt=cpt->rpt;
        ptr->lpt=cpt;
        // cpt->rpt->lpt=ptr;//longest one XD 
        // isme humcpt ka rpt ka lpt jo cpt se juda hua tha ab use ptr se jod dena kyukicpt ke 
        // just baad ab ptr arha connection maintan rhna cchaiayeee ;
        cpt->rpt=ptr;// cpt usse piche rhega ptr uska one next hoga;
        
        display();

        
    }
    void delete_beg();
    void delete_beg(){
        struct node *ptr,*cpt;
        ptr=first;
        ptr->rpt=cpt;
        cpt->rpt=NULL;
        
        first=cpt;
        display();
        free(ptr);
        
        
    }
    void delete_end();
    void delete_end(){
        struct node *ptr,*cpt;
        //ptr ko last tk leke janan
        while(ptr->rpt!=NULL){
            ptr=cpt;// ptr ko just ek phle pkd liyaaa
            ptr=ptr->rpt;

        }
        cpt->rpt=NULL;// last second wale ka link null krdiya jis means age kuch nhi h;
        free(ptr);
        display();

    }  
    void delete_btw();
    void delete_btw(){
        int data ;
        struct node *ptr,*cpt;
        printf("enter after which you want to delete the node");
        scanf("%d",&data);
        while(ptr->info!=data){
              ptr=ptr->rpt;// aage bdh rha h;
        }
        ptr->lpt->rpt=ptr->rpt;// read ptr -> rpt as ptr ka rpt;
        ptr->rpt->lpt=ptr->lpt;
        
        free(ptr);
        display();
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
        insert_beg();
    }

    else if(choice==2){
        insert_end();
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

    else{
        printf("hatt pagal");
    }
    }
    }
    
    }


