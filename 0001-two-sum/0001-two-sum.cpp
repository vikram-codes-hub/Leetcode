class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int index=0;
        for(auto i:nums){
            int ss=target-i;
            if(mp.find(ss)!=mp.end()){
                return {index,mp[ss]};
            }
            mp[i]=index;
            index++;
        }
        return {-1,-1};
    }
};