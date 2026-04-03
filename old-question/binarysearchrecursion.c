#include<stdio.h>
#include<conio.h>

int BS(int A[],int low, int high , int k);

int main(){
int A[]={30,40,50,60,70,80};
int low = 0;
int x = sizeof (A)/ sizeof A[0]; //bda upr chot a niche
int high = x -1 ;
int k=40

;
//int mid = low + high / 2;
// call krna jruri h main se connect toh kro;
int result = BS(A, low, high, k);
    
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index: %d\n", result);
    
    return 0;

}
int BS( int A[],int low,int high,int k){
    if (high>=low){
  int mid = low + high / 2;
  if(A[mid]==k){return mid; }  //base condition
  if(A[mid]>k){return BS(A,low,mid-1, k);}
  else{return BS(A,mid+1,high, k);}

  //mid ko kyu hi lena function defination me votoh baar change horha h;
  
    }
return -1;
}
//mistake done many times 
//calling me [] nhi lgane ek bar likh diya ki array hiayega toh har baar calling me nhi lgana
