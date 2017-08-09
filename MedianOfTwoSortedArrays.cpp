#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //merge O(m+n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0,j = 0;
        vector<int>  v1;
        //median = (m + n) / 2;
        
        while(i<nums1.size() || j<nums2.size() ){
            if(i>=nums1.size() || (j<nums2.size() && nums1[i]>nums2[j])) v1.push_back(nums2[j++]);
            else v1.push_back(nums1[i++]);
        }
        int t = v1.size();
        if(t%2 == 0) return (double)(v1[t/2-1]+v1[t/2]) / 2.0;//if(t & 0x1)
        else return (double) v1[t/2];
    }
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2){
        /*
        int k = (m + n)/2;
        if (k == 0) return min(nums1[0],nums2[0]);
        if (nums1[k/2-1] == nums2[k/2-1]) return nums1[k/2-1];
        if (nums1[k/2-1] < nums2[k/2-1]){
            findMedianSortedArrays2(nums1.begin()+k/2,nums2);
        }
        else{
            findMedianSortedArrays2(nums1, nums2.begin()+k/2);
        }
        */
        const int m = nums1.size();
        const int n = nums2.size();
        int total = m + n;
        if(total & 0x1)
            return find_kth(nums1.begin(),m,nums2.begin(),n,total/2);
        else 
            return (find_kth(nums1.begin(),m,nums2.begin(),n,total/2) 
            + find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1))/2;
    }
    double find_kth(vector<int>::const_iterator A,int m,vector<int>::const_iterator B,int n,int k){
        if(m > n) return find_kth(B,n,A,m,k);
        if(k == 1) return min(*A, *B);
        if(m == 0) return *(B+k-1);
        int ia = min(k / 2,m);
        int ib = k - ia;
        if(*(A+ia-1) < *(B+ib-1)) return find_kth(A + ia,m-ia,B,n,k-ia);
        else if(*(A+ia-1) > *(B+ib-1)) return find_kth(A,m,B+ib,n-ib,k-ib);
        else return *(A+ia-1);  
    }
};
int main(){
    Solution s;
    int a1[] = {1,3};
    int a2[] = {2,4};
    vector<int> nums1(a1,a1+2);
    vector<int> nums2(a2,a2+2);
    double median = s.findMedianSortedArrays2(nums1,nums2);
    cout<<median<<endl;
}