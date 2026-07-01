class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int ls=0,total=0;
        for(auto i:nums){
            total+=i;
        }

        for(int i=0;i<nums.size();i++){
            int rs=total-ls-nums[i];
            if(rs==ls){
                return i;
            }else ls+=nums[i];
        }

        return -1;
    }
};