class Solution {
public:
    int pivotIndex(vector<int>& nums) {
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

/*
ls=0 ts=28 
i=0->rs=ts-ls-cuur   28-0-1 no
*/