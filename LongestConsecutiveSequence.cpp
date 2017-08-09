#include <iostream>
#include <vector>
#include <algorithm>
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
};
int main(){
    Solution s;
    int a[] = {1,2,0,1};
    vector<int> nums(a,a+4);
    int length = s.longestConsecutive(nums);
    cout<<length<<endl;
}