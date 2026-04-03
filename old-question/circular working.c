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
void insert_last();
void insert_btw();
void delete_beg();
void delete_btw();
void delete_last();


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
        ptr->link=cpt;//ptr se next pe cpt ko krdiya
        ptr=cpt;
        printf("Do you want to create more Nodes? Press 'Y' for yes and 'N' for no:");
        fflush(stdin);
        scanf("%c",&ch);


    }
    while(ch=='y');//agar yeh true nhi hua toh ptr ka link null hoga;

    ptr->link=first;// sb end hogya toh yeh dubara first se connect hojayega 
    //change 
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
//yha toh print ko baad likho tb dubara print krna nhi pdrga

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
        delete_btw();
    }
    else if(choice==6){
        delete_last();
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
    display();   
    
    
   
   // ptr(free); free kyu krna h delete thodi horha h;
   
}
void insert_last(){
    // last tk first leke jana h fir milana h 
    struct node *ptr,*cpt;
    cpt=first;
    while(cpt->link!=first){
        cpt=cpt->link;

    }
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter new info");
    scanf("%d",&ptr->info);
    // khali phle bhro
    ptr->link=first;
    cpt->link=ptr;//last me jodo
    display();

    
    
}
void insert_btw(){
    int data;
    struct node *ptr,*cpt;
    printf("enter info after which node  want to add new node");
    scanf("%d",&data); 
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter info to insert in between ");
    scanf("%d",&ptr->info);
    cpt=first;
    //agar 30 rk chlega toh 30 ke baad hi print krna h;
    while(cpt->info!=data){
        cpt=cpt->link;
    } 
    ptr->link=cpt->link;
    cpt->link=ptr;
    display();
    //pura same h ll se kyu ki koi jodne ki need nhi first or last ko hum firsst or last se khel hi nhi rhee
}
void delete_beg(){
    struct node *cpt,*ptr;
    ptr=first;
    cpt=first;
    while(ptr->link!=first){
        ptr=ptr->link;
    }
    ptr->link=cpt->link;
    first=cpt->link;
    free(cpt);
    printf("after deletion in begining");
    display();
}
void delete_last(){
    struct node *ptr,*cpt;
    cpt=first;
    while(cpt->link!=first){
        ptr=cpt;//cpt ko phle hi pkd liaa
        cpt=cpt->link;
    }
    ptr->link=first;
    free(cpt);
    printf("after deletion in last");
    display();
}
void delete_btw(){
    int data;
    struct node *ptr,*cpt;
    printf("enter node which you want to delete");
    scanf("%d",&data);
    ptr=first;
    while(ptr->info!=data){
        cpt=ptr;// uske piche wala pkd liya;
        ptr=ptr->link;

    }
    cpt->link=ptr->link;
    free(ptr);

    printf("after deletion in btw");
    display();

}