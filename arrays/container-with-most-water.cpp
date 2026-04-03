#include<stdio.h>
#include<bits/stdc++.h>

using namespace std ; 

int main() { 

    vector<int> arr = {1,8,6,2,5,4,8,3,7};
                    // 0,1,2,3,4,5,6,7,8,
    int n = arr.size() ; 

    //brute toh likh diya better ya optimal dhundn h 
    // is keliye me kya kr rha hounga ki me do aise eleemnt dhundunga jinka max sum ho 
    // or i j me gap jada ho two sum ka recall krte h two sum me toh brute force tha 0(n2) har element ke liye 
    // toh better merko jo yaad arha h voh kuch aisa tha ki ; two sum me toh target diya hota tah toh usse nikalte the 
    // jiski choti height h use move kro maanlo do pointer h 1 7 
    // chota 1 move 8 7 store kiya 7 ko move kiya 8 3 84 85 83 86             

    // rule h area nikalne ka ki 
    // min nikalna h  dono kisi height ka or index wale se minus krdena h 
    // for eg here in optimal array 
    // min ( 8,7) = 7 7*7 optimal 

    //  brute force likhne ka try krte h phle
    int maxx = 0 ; 
    int smaxx = 0 ; 
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j ++){
            if(i<j){
            maxx = min(arr[i],arr[j]) * (j-i); 
            }
            smaxx = max(maxx,smaxx);
        }
    }
    cout << smaxx;


}