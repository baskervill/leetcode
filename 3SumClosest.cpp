#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int min = 100000;
        int result;
        for(int i = 0;i < nums.size();i++){
            int low = i + 1;
            int high = nums.size() - 1;
            int a = nums[i];
            int b;
            int c;
            while(low < high && low < nums.size() - 1 && high > 0 ){
                b = nums[low];
                c = nums[high];
                int sum = a + b + c;
                int gap = abs(sum - target);
                if(gap < min){
                    result = sum;
                    min = gap;
                }
                else if(sum < target){
                    low ++;
                }
                else{
                    high--;
                }
            }
        }
        return result;
    }
};
int main(){
    int a[] = {-1,2,1,-4};
    int target = 1;
    vector<int> nums(a,a+4);
    Solution s;
    int res = s.threeSumClosest(nums, target);
    cout<<res<<endl;
    return 0;
}