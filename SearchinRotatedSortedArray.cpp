#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size();
        int mid = 0;
        while(first!=last){
            mid = first + (last - first)/2;
            if(nums[mid]==target) return mid;
            if(nums[first]<nums[mid]){
                if(nums[first]<=target && target<nums[mid])
                    last = mid;
                else first = mid + 1;
            }
            else{
                if(nums[mid]<target && target<=nums[last-1])
                    first = mid + 1;
                else last = mid;
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    int m;
    vector<int> nums;
    int target = 5;
    while(scanf("%d",&m) == 1){
        nums.push_back(m);
    }
    //ctrl + d to end the input !!!
    //use gdb by gcc -g !!!
    int res = s.search(nums,target);
    printf("%d\n",res);
}