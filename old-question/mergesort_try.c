#include<stdio.h>
#include<conio.h>
void MS(int A[],int low , int high );
void M(int A[],int low ,int mid , int high);

//glti
//main ke aage () bhul gya;
// arrray declarationn me int A[] na bhule;
// calling me void int ki jrurat bbnhi 

int main(){
    int low=0;
    int A[]={38,27,43,3,9,82,10};
    int x = sizeof A/sizeof A[0]; //kitne elements h 
    int high = x - 1 ;// high hmesha x se ek kam hoga cause 0 se start hota h na ki 1 se 
    MS(A,low,high);
    printf("Sorted array: ");
    for (int i = 0; i <= high; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;

}
void MS(int A[],int low , int high ){
if (low<high){
    // phli baar mid lga h or define kro int ke sath'
        int mid=(low+high)/2;
        MS(A, low , mid - 1);//dividing into two halvess
        MS(A,mid + 1,high);//dividing into two half
        M(A, low ,mid, high);// then merge the two half

    }
}


void M(int A[],int low ,int mid, int high){
    int i,j,k;
    int n1 = mid - low + 1 ;
    int n2 = high - mid;
    // agar 5 elements h toh;
    // l = (0+5/2=2)=m ; 2 - 0 + 1 = 3 
    // r = 4 - 2 = 2
    // l 3 me or r 2 me btega
    int L[n1],R[n2];

    // sbse phle ab saaare devided h toh hum ek temp array me bharenge sab kuch
    for(i=0;i<n1;i++){
        // l ke andar bharte h l chalega n1 tk mtlb 3 tk
        L[i]=A[low+i];
        //l[0]=A[low+0] 0+0 A ke 0 ka element l ke 0 me ; 
        //0+1 
        //0+2
        //aise krke bharte rhenge
        // jb tk n nhi ata
        // n-1 tk chlega mtlb 0,1,2 bharega; 

    }
    
    for(j=0;j<n2;j++){
        R[j]=A[mid + 1 + j];
        //3,4 bharega
    }
    i=0;
    j=0;
    k=low;
    //k jruri h low se chale naa ki 0 se kya pta sub arrays 0 se na ho;

    //ab hum krenge merge jo element bate huye h
    // jb tk chlega tb tk koi khatam nhi hota
   while(i<n1 && j<n2){
         if(L[i]<=R[j]){ //dono array compare krenge 
                         //agar chota hoga niche ajayaega or aage final array me ajayega
            A[k]=L[i];
            i++;
            //jo utar gya won plus hogya
         }
         else{
            A[k]=R[j];
            j++;
         }
         k++;// yeh hr baar horha h ++ k

   }
   // ab dekhna h ki kuch bcha toh nhi h agr bcha h toh usko bhi likho;
   while(i<n1){
    A[k]=L[i];
    i++;
    k++;

   }
   while(j<n2){
    A[k]=R[j];
    j++;
    k++;
    
   }
    
    
    }
