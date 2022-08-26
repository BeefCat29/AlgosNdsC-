/**
  Created by karthik on 8/26/2022.
**/
#include <bits/stdc++.h>
using namespace std;

bool checkStroboGrammaticNumber(string nums){
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right){
        int leftNum = nums.at(left) - '0';
        int rightNum = nums.at(right) - '0';

        if(leftNum == 6){
            if(rightNum != 9) return false;
        }else if(leftNum == 9){
            if(rightNum != 6) return false;
        }else if(leftNum == 8){
            if(rightNum != 8) return false;
        }else if(leftNum == 1) {
            if (rightNum != 1) return false;
        }else if(leftNum == 0){
            if(rightNum != 0) return false;
        }else{
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(){
    cout << checkStroboGrammaticNumber("808") << " ans";
}
