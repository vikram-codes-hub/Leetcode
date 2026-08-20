class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()==3)return nums[0]*nums[1]*nums[2];
        if(nums.size()<=2)return -1;

        sort(nums.begin(),nums.end());
        int n=nums.size();

        return max(nums[0]*nums[1]*nums[2],max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]));
    }
};