#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        unique(nums.begin(),nums.end());
        int length = 0;
        int a = nums[0];
        int max = 0;
        for(vector<int>::iterator iter = nums.begin() + 1;iter!=nums.end();iter++){
            if(*iter == a + 1){
                a = *iter;
                length++;
                if(max < length) max = length;
            }
            else{
                length = 0;
                a = *iter;
            }
        }
        return max + 1;
    }
    int longestConsecutive2(vector<int>& nums){
        unordered_map<int,bool> used;
        int max = 0,length = 0;
        /*
        for(vector<int>::iterator iter = nums.begin();iter != nums.end();iter++){
            used[*iter] = false;
        }
        */
        for(auto i : nums) used[i] = false;
        for(int i = 0; i<nums.size();i++){
            if(used[nums[i]] != true){
                used[nums[i]] = true;
                int j = 1, k = 1;
                while(used.find(nums[i]+j) != used.end() ){
                    used[nums[i]+j] = true;
                    j++;
                }
                while(used.find(nums[i]-k) != used.end()){
                    used[nums[i] - k] = true;
                    k++;
                }
                length = j+k-1;
                if(max < length) max = length;
            }

        }
        return max;
    }
    
};
int main(){
    Solution s;
    int a[] = {1,2,0,1};
    vector<int> nums(a,a+4);
    int length = s.longestConsecutive2(nums);
    cout<<length<<endl;
}