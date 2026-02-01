#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std ;

int main() {
  vector<int> nums = {1,2,3,0,0,4,5};

    int j=-1;
        for(int i = 0 ; i < nums.size(); i ++){
            if(nums[i]==0){
                j = i ;
                break ; // yeh likhna jruri h 
            }
        }

        if(j == -1){
            return 0;
        }

        for(int i = j + 1; i < nums.size();i ++){
            if(nums[i]!=0){
                swap(nums[j],nums[i]);
                j++;
            }
        }

    for (int i = 0; i < nums.size(); i++) {
       cout << nums[i];
    }




}
