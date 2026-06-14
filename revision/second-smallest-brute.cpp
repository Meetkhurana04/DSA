#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 4, 5, 2, 3};
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i : arr){
      cout << i << " ";
    }
    cout << endl << "second smallest : " << arr[2];
}
