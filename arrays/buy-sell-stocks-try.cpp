#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int ar[2] ;
    int n = arr.size();
    int mx = 0 ; 

    // brute force krte h on2

    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){ // j = 1 leskte h kykuki ise baadke hi dekhne h 
            int summ = arr[j]-arr[i];
            if(summ>mx){
                mx = summ ; 
                ar[0]=arr[j];
                ar[1]=arr[i];
                //  iski jgh do ariable bhi rkh skte h ;;
            }
        }

    }

    cout << mx << " hello" << endl;
    cout << "sbse jyada profit hoga jb aap kharidoge " << ar[0] << endl ;
    cout << "sbse jyada profit hoga jb aap bhechogee " << ar[1] << endl ;


    // 0n2 se optimeise kese kr rha hounga m 
    // two sum me toh ek target hotah h jo ki target - current krke hum dhundskt eh via hashing 
    // and usme better appraoch hogi two optimal waali ; jisme kya horah hoga sorted me number h 
    // and me 1 oe 2 pkdunga aree  nhi bni baat 1 3 14 15 jyada bhar nikl gye 2 5 minus krdo 

    // or koi apparocah nhi smjh arhi h 



}