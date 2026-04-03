//circular link
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;

};
struct node *first;
void create();
void display();
void insert_beg();
void create(){
    char ch;
    struct node *ptr,*cpt;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter node info");
    scanf("%d",&ptr->info);
    ptr->link=ptr;
    first=ptr;
    do{
        
        cpt=(struct node*)malloc(sizeof(struct node));
        printf("enter node info");
        scanf("%d",&cpt->info);
        ptr->link=cpt;//doubt
        ptr=cpt;
        printf("Do you want to create more Nodes? Press 'Y' for yes and 'N' for no:");
        fflush(stdin);
        scanf("%c",&ch);


    }
    while(ch=='y');//agar yeh true nhi hua toh ptr ka link null hoga;

    ptr->link=first;// sb end hogya toh yeh dubara first se connect hojayega 
    
}
void display(){
    struct node *ptr;
    ptr=first;
    printf("your node info");
    while(ptr->link!=first){
        
    printf("%d\n",ptr->info);
    ptr=ptr->link;
    }
    printf("%d\n",ptr->info);// jab sb end hojayega toh vese toh
    //print nhi hoga ptr info kyuki vo check kr rha h ki yeh first ko point kr rha h vhi ruk jayega print nhi kr rha abut abhii bhi woh last ko point kr rha h toh ise loop se bhar pakad ke print krwado
     
}
int main(){
    int choice;

    create();
    display();
    
     for(;;){
  printf("Enter your choice:");
    scanf("%d",&choice);

    if(choice==0){
         break;
    }

    else if(choice==1){
        insert_beg();
    }

    
    
    }



    return 0;
}
void insert_beg(){
    struct node *ptr,*cpt;

    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter new info which has to be stored in the begining");
    scanf("%d",&ptr->info);
    cpt=first;// abhi cpt first se shuru horha h
    // ekk se bnayenge ek se last tk leke jayengeee
    while(cpt->link!=first){
        cpt=cpt->link;// isse yeh ag ebdhtya rhega
        //jo khali h usse phle fill krte h;
        ptr->link=first;//new ko first wale se jod diya
        first=ptr;//ab new ka hath first me dediya
        cpt->link=ptr;//last wale cpt ko first se jod diya
    }
    
   
   // ptr(free); free kyu krna h delete thodi horha h;
   display();
}
