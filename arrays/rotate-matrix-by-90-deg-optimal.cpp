#include<conio.h>
#include<bits/stdc++.h>
using namespace std ;
int main() { 

     int n = 4; 
    int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}; 
    for ( int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl ;
    }

    // transpose krna h uske liye 

    for(int i = 0 ; i<=n-1 ; i++){
        for(int j = i + 1 ; j <= n -1 ; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
// yhe wala tranpsoe ka logic thoda optimal jyada h or kafi saari pe bhi lgega

    cout << "transpose " << endl ;

     for( int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl ;
    }

// tranpose hogya ab kya krna h reverse each 
//reverse ka direct fucntion bhi htoa h nhi toh yeh krlo 
  for( int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n/2 ; j++){
            // j ko adha chlana h 
            swap(arr[i][j],arr[i][n-1-j]);
        }
        
    }

    cout << "after reveerse " << endl ;

      for( int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl ;
    }



}