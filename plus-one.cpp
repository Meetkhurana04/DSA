#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;


// digits agar 23 ho toh 24 hoajyegi simple plus one add krnah  
// digits 1 9 h toh add krna h 1 toh woh 2 , 0 krna hoga isme 
// last wale ko zero krenge and usse n-1 wale ko plus one 
// toh 9 wale case me 0 kar rhe honge and but lgatar 9 aayega usko kese dekhnge

int main() {
    vector<int> digits = {1,2,3};
    int n = digits.size() - 1;
    int x = digits[digits.size()-1] ; 
   
        // if less than 9 toh woh just plus one krdenge 
    
     // agar lessthan 9 nhi h toh mtlb woh 9 h toh use 0 krdenge 
      
        // fir se loop chlyenge n-1 ko 9 se dekhnge 
        // if we have only one digits that is 9 toh uske liye hum new array lenge int [] new number length + 1
        // int [] newnumber = length = (n+1) = 2 // isko bydefault zero hoga 
        // and isme hum firs first degit 1 kar rhe honge digits[0] = 1 

        //craxy concept milgya h agr me soch rha tha ki 99 ko 100 bnana h fornt me 
        // one kese add akr rrhogunga toh isko bdiya trika h ki hum reverse krde
        // kyuki insertion at alst is easy than insertion at end

        // toh phle digits ko reverse krdenge 
    
      // brute force me toh yhe hi hoga ki array se nikalo and then + 1 krke array me add krdo

      cout << "brute force" << endl;
      int sum = 0 ;
      int i = 0 ; 
      for(auto it : digits){
        sum = sum * 10 + it;
        i++;
      }

      cout << sum ;
      sum = sum + 1;
      // vector<int> y[];
      // 123 
      // 123 me se 1 ko add krna h me jaada se jaada last ko nikal skta hu 
      // len nikalete h
      int count =  -1; 
      int temp = sum ;
      while(temp>0){
        temp=temp/10;
        count ++ ;
      }
     
      cout << endl << "question" << endl ;
      cout << "count : " << count << endl ;
      cout << "sum : " << sum << endl;
      
      // int xx = round(pow(10,count));
      // // xx= xx/10;
      // int yy = sum/xx;
      // cout << "pow : " << xx << endl;
      // cout << yy ; 
      
      i = 0;
     digits.clear();   // purana digits hata do

while (count >= 0) {
    int power = round(pow(10, count));
    int digit = sum / power;
    digits.push_back(digit);
    sum = sum % power;
    count--;
}
      cout << "output :";
      for(int it : digits){
        cout << it ;
      }


      // while(sum>0){
      //   y.push_back();
      // } 
    
}