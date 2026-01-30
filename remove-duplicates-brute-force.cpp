#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> removeDuplicates(vector<int> &arr) {
         
      set <int> se ;
     for(auto it : arr){
         se.insert(it);
        
    }
    vector<int> x;
    for ( auto it :se){
        x.emplace_back(it);
    }
    
    return x;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> result = obj.removeDuplicates(arr);

    // for (int x : result) {
    //     cout << x << " ";
    // }

    return 0;
}
