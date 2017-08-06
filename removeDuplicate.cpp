Class Solution{
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
}
int main(){
    Solution s;
    int res = s.removeDuplicate(nums);
    cout<<"length:"<<res<<endl;
    cout<<nums[i]<<" ";
}