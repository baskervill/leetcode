#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> hash;
        vector<int> result;
        int numberToFind;
        for(int i = 0; i < nums.size();i++){
            numberToFind = target - nums[i];
            if(hash.find(numberToFind) != hash.end()){
                result.push_back(hash[numberToFind] );
                result.push_back(i );
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;    
    }
};
int main(){
    Solution s;
    vector<int> key;
    vector<int> nums;
    int target = 9;
    srand(0);
    for(int i = 0;i < 9;i++){
        nums.push_back(i);
        printf("%d ",nums[i]);
    }
    key = s.twoSum(nums,target);
    for(vector<int>::iterator iter = key.begin();iter != key.end();iter++){
            printf("%d ",*iter);
    }
    return 0;

}