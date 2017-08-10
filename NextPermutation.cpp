#include <iostream>
#include <vector>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};
int main(){
    Solution s;
    int res = s.next_permutation(nums.begin(),nums.end());
}
