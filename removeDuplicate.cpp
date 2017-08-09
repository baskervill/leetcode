#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
        int removeDuplicate(vector<int>& nums){
            if(nums.empty()) return 0;
            int index = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[index]!=nums[i]){
                    nums[++index] = nums[i];
                }
            }
            return index + 1;
        }
        int removeDuplicate1(vector<int>& nums){
            return distance(nums.begin(),unique(nums.begin(),nums.end() ));
        }
};
int main(){
    Solution s;
    int a[8] = {1,1,2,2,3,3,4,5};
    vector<int> nums(a,a+7);
    int res = s.removeDuplicate1(nums);
    cout<<"length:"<<res<<endl;
    //cout<<nums[i]<<" ";
}