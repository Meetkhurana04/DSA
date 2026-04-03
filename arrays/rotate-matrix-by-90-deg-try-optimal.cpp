#include<conio.h>
using namespace std ;
#include<bits/stdc++.h>

int main() { 
    int n = 4; 
    int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    // inhe rotate krna h by saha method 
    for ( int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl ;
    }

  // first transpose then reverse 
  // hume jo traverse krna h woh bhi top ka krna hoga cuase dono baar ka chlega toh fir saem ajayega 
// transpose logic isse kya hoga half hi triangle se deal kr rhe honge hm
// agar dono side se deal krenge toh issue hoskta h liek chije again swap hoke orignal hojayegi 
         
   for ( int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
           if(j>=i){
            continue ; 
           }
           else{
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp; 
            
           }
        }
    }

cout << "tranpose" << endl ;
      for ( int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl ;
    }

    // transpose hogya ab reverse krdete h 
      for ( int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n/2 ; j++){
            int temp=arr[i][j];
            arr[i][j]=arr[i][n-1-j];
            arr[i][n-1-j]=temp;
        }
        
    }

    cout << "reverse" << endl ;
      for ( int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl ;
    }
    
}