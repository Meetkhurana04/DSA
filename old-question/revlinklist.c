
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;

};
struct node *first;

void display();
void create();
void revlist();


void create(){
    char ch;
    struct node *ptr,*cpt;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter info : ");
    scanf("%d",&ptr->info);
    ptr->link=NULL;
    first=ptr;
   
    do{
      cpt=(struct node*)malloc(sizeof(struct node));
      
      printf("enter info : ");
      scanf("%d",&cpt->info);
       
      ptr->link=cpt;
      ptr=cpt;// ptr ko second pe krdiya
      
       printf("do you want to add more node press y and n for exit : ");
       scanf("%s",&ch);
       fflush(stdin);
      
    }
    while(ch=='y');
    ptr->link=NULL;
    


}
void display(){
    struct node *ptr;
    ptr=first;
    printf("your info is : ");

    while(ptr!=NULL){
        printf("%d\n",ptr->info);
        ptr=ptr->link;// ek hi ptr ko aage bdhte rhna h  
    }
}

void revlist(){
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
int main(){
    int choice;
    create();
    display();
    printf("press 1 for rev list");
    scanf("%d",&choice);
    if(choice==1){
        printf("reverse link list is:");
        revlist();
    }
}

