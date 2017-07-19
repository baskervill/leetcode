#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
public:
    vector<vector<int> > threeSum(vector<int>& nums){
        vector<vector<int> > result;
        sort(nums.begin(),nums.end());
        //skip the duplications,have a problem
        vector<int>::iterator point = unique(nums.begin(),nums.end());
        nums.erase(point,nums.end());
        for(int i = 0; i < nums.size();i++){
            int low = i + 1;
            int high = nums.size() - 1;
            int a = nums[i];
            while(low < high && low < nums.size() - 1 && high > 0 ){
                int b = nums[low];
                int c = nums[high];
                if(a+b+c == 0){
                    vector<int> v;
                    v.push_back(a);
                    v.push_back(b);
                    v.push_back(c);
                    result.push_back(v);
                    high--;
                    low++;
                }else if(a+b+c < 0){
                    low++;
                }else{
                    high--;
                }
            }
        }
        return result;
    }
};

/*
vector<vector<int> > threeSum(vector<int> &num) {

    vector< vector<int> > result;

    //sort the array, this is the key
    sort(num.begin(), num.end());

    int n = num.size();

    for (int i=0; i<n-2; i++) {
        //skip the duplication
        if (i>0 && num[i-1]==num[i]) continue;
        int a = num[i];
        int low = i+1;
        int high = n-1;
        while ( low < high ) {
            int b = num[low];
            int c = num[high];
            if (a+b+c == 0) {
                //got the soultion
                vector<int> v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                result.push_back(v);
                // Continue search for all triplet combinations summing to zero.
                //skip the duplication
                while(low<n-1 && num[low]==num[low+1]) low++; 
                while(high>0 && num[high]==num[high-1]) high--; 
                low++;
                high--;
            } else if (a+b+c > 0) {
                //skip the duplication
                while(high>0 && num[high]==num[high-1]) high--;
                high--;
            } else{
                //skip the duplication
                while(low<n-1 && num[low]==num[low+1]) low++;
                low++;
            } 
        }
    }
    return result;
}
*/
int main(){
    Solution s;
    int S[6] = {-1,0,1,2,-1,-4};
    vector<int> nums;
    for(int i = 0;i < 6;i++){
        nums.push_back(S[i]);
    }
    vector<vector<int> > key = s.threeSum(nums);
    for(vector<vector<int> >::iterator iter = key.begin();iter != key.end();iter++){
        for(vector<int>::iterator iter1 = (*iter).begin();iter1 != (*iter).end();iter1++){
            cout<<*iter1<<" ";
        }
        cout<<endl;
    }
}