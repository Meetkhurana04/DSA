#include<bits/stdc++.h>
#include<conio.h>

using namespace std ;

int main() {

vector <int> arr= {-1,4,5,-2,-3};
int n = arr.size();

// isme kya hoga ki output whi smae form me dnea h ek positvie ek negative 
// but cathc is that here no. of pos is not equal to no. of negative 
// so isme direct whi opitmal waale approach lgega 
// brute lga skte h 
// pichel wala ka opitmal nhi lgaskte h hum ispe kyuki 
// ki ek loop me fill krna mushkil h pos index neg index kese smjbhlenge 

// brute wala krskte h kyuki ek side count krle 

vector<int> pos,neg;
for(int i = 0 ; i < n ; i ++)
{
    if(arr[i]>0){
        pos.push_back(arr[i]);
    }
    else{
        neg.push_back(arr[i]);
    }
}
// isme do case h pos bda h ya neg bda h 

if(pos.size()>neg.size()){
    // negative chota h toh mtlb hume negative tk chlna h 
    for(int i = 0 ; i < neg.size() ; i++ ){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];

        // posor negative fix bhardenge alg alg 

    }
    int index = neg.size() * 2 ; 
    for(int i = neg.size();i<pos.size();i++){
        arr[index] = pos[i];
        index++;
    }
}

else { 

// this scenalrio handle the  case of equal and jb negative me km ho
 for(int i = 0 ; i < pos.size() ; i++ ){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];

        // posor negative fix bhardenge alg alg 

    }
    // agar incase woh equal huye toh niche wala chlega hi nhi 
    int index = pos.size() * 2 ; 
    for(int i = pos.size();i<neg.size();i++){
        arr[index] = neg[i];
        index++;
    }
}


for(int it : arr){
    cout << it << " "; 
}


}