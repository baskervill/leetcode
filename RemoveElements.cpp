#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator iter ;
        while(iter != nums.end()){
            iter = find(nums.begin(),nums.end(),val);
            if(iter != nums.end())
                nums.erase(iter);  
        }
        return nums.size();
    }
    //distance(nums.begin(),remove(nums.begin(),nums.end(),val))
    //nums[j++] = nums[i]
};
int main(){
    Solution s;
    int a[] = {3,2,2,3};
    int val = 3;
    vector<int> nums(a,a+4);
    int res = s.removeElement(nums, val);
    cout<<res<<endl;
    return 0;
}