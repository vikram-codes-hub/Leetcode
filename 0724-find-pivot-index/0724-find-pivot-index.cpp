class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int t=0,n=nums.size(),ls=0;
        for(auto i:nums){
            t+=i;
        }

        for(int i=0;i<n;i++){
             int rs=t-nums[i]-ls;
             if(ls==rs)return i;
             ls+=nums[i];
        }
        return -1;
    }
};