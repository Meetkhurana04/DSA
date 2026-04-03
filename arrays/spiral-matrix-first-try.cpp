#include<stdio.h>
#include<bits/stdc++.h>
using namespace std ; 

int main() {

    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}} ;
    // mereko spiral me print krna h 
    //output be liek 1 2 3 6  9 8 7 4 5
    // n variable = n 
    // begin var =0

    // kese merko phel i = 0 pe j bdahana h until n possible 
    // fir j bdhana h until n ends 
    // n -1 
    // fir i -- krna h until 0 begin se compare hoga 
    // begin + 1 
    // fir j -- krna h until 1

    // i bdhana h until n
    //count leke chl legen ki agar saare print hogye toh ruk jaayenge 

    // i bdhao jb tk bdhe 
    // j bdha jb tk bdhe
    // j ghatao jb tk gahte
    // i ghatoa jb tk ghate 
    // loop me hona chahiye yeh 

    int right = 2;
    int left = 0; 
    int trav = 9 ; 
    int i = 0  ;
    int j = 0 ; 
    int down = 2 ;
    int top = 0 ;  

    while(trav>0){
        
        while(j<=right){
            cout << arr[i][j] << " ";
            trav--;
            j++; //1 2 3 ==> 0 1 2
        } // i =0 j = 2
        top=top+1;
        // down move
        j--;
        i++;
        while(i <= down){ //0<3 0 1 2 => 4 8 12  
            cout << arr[i][j] << " ";
            trav--;
            i++;
        }//i = 2 j = 2
        i--;
        j--;
        right--;
        if(top<=down){
        while(j>=left){ // 2>0 ==> 2,1, ==> 11 10 
                cout << arr[i][j] << " ";
                trav--;
                j--;  
        }// i = 2 j = 2
        down--;
        j++;
        i--;
    }
    if(left <= right){
        while(i>=top){ //2>1
            cout << arr[i][j] << " ";
            trav--;
            i--;
        } // ==> 5
        //i =1 j =
        left++;
        i++;j++;
    }

    }

}