#include<iostream>
#include<vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main() {

vector<int> n1 = {2,2,3,4,5};
vector<int> n2 = {2,2,3,4,5};

map<int ,array<int,2>> mp ;

for ( int x : n1){
    mp[x][0] = 1;
}
for (int x : n2){
    mp[x][1]=1;
}

for (auto &x : mp ){
    // map as a pair ki trh chlega

    if(x.second[0]==1 && x.second[1]==1){
        cout << x.first << " ";
    }
}








}