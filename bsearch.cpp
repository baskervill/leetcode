#include <cstdio>
#include <vector>
using namespace std;
/*
int bsearch(int *A, int first, int last, int target){
    int m = 0;
    while(first<last){
        m = first + (last - first)/2;
        if(A[m]==target)
            return m;
        else if(A[m]>target) last = m;
        else first = m + 1;
    }
    return -1;

}
*/
int bsearch(vector<int>& nums , int target){
    int m = 0;
    int first = 0;
    int last = nums.size();
    while(first<last){
        m = first + (last - first)/2;
        if(nums[m]==target)
            return m;
        else if(nums[m]>target) last = m;
        else first = m + 1;
    }
    return -1;

}
int main(){
    vector<int> nums;
    for(int i=1;i<11;i++){
        nums.push_back(i);
    }
    int res = bsearch(nums,5);
    printf("%d\n",res);
}